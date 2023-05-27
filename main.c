/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:33:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/05/27 13:48:08 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_print_stacks(t_prog pg)
{
	printf("\nA stack\n");
	for (int i = 0; i < pg.a.size; i++)
		printf("%d\n", pg.a.array[i]);
	printf("\nB stack\n");
	for (int i = 0; i < pg.b.size; i++)
		printf("%d\n", pg.b.array[i]);
	// printf("\nsorted stack\n");
	// for (int i = 0; i < pg.a.size; i++)
	// 	printf("%d\n", pg.sorted[i]);
	printf("\n");
}

void	ft_exit(t_prog *pg, int c)
{
	if (c == 1)
		ft_putstr_fd("Error\n", 2);
	if (pg)
	{
		if (pg->a.array)
			free(pg->a.array);
		if (pg->b.array)
			free(pg->b.array);
		if (pg->sorted)
			free(pg->sorted);
	}
	//system("leaks push_swap");
	exit(c);
}

int	ft_psw_atoi(t_prog *pg, char *str)
{
	int		i;
	int		sign;
	long	nbint;

	i = 0;
	sign = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		ft_exit(pg, 1);
	nbint = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbint = nbint * 10 + str[i] - '0';
		i++;
		if (sign > 0 && nbint > INT_MAX)
			ft_exit(pg, 1);
		else if (sign < 0 && -(nbint) < INT_MIN)
			ft_exit(pg, 1);
	}
	return (nbint * sign);
}

void	convert(t_prog *pg, int ac, char **av)
{
	int	i;

	i = -1;
	pg->a.array = malloc(sizeof(int) * ac);
	pg->b.array = malloc(sizeof(int) * ac);
	if (!pg->a.array || !pg->b.array)
		ft_exit(pg, 1);
	while (++i < ac - 1)
	{
		pg->a.array[i] = ft_psw_atoi(pg, av[i]);
		pg->a.size++;
	}
}

void	ft_char_check(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac - 1)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && !(j == 0 && (av[i][j] == '-'
						|| av[i][j] == '+')))
				ft_exit(0, 1);
		}
	}
}

void	ft_issorted(t_prog *pg)
{
	int	i;

	i = -1;
	while (++i < pg->a.size - 1)
		if (pg->a.array[i] > pg->a.array[i + 1])
			return ;
	ft_exit(pg, 0);
}

void	ft_double_check(t_prog *pg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < pg->a.size)
	{
		j = i;
		while (++j < pg->a.size)
			if (pg->a.array[i] == pg->a.array[j])
				ft_exit(pg, 1);
	}
}

void	ft_sort_3(t_stack *stack, char c)
{
	if (stack->array[1] < stack->array[0] && stack->array[0] < stack->array[2])
		ft_swap(stack, c);
	if (stack->array[2] < stack->array[1] && stack->array[1] < stack->array[0])
	{
		ft_swap(stack, c);
		ft_rev_rot(stack, c);
	}
	if (stack->array[1] < stack->array[2] && stack->array[2] < stack->array[0])
		ft_rot(stack, c);
	if (stack->array[0] < stack->array[2] && stack->array[2] < stack->array[1])
	{
		ft_swap(stack, c);
		ft_rot(stack, c);
	}
	if (stack->array[2] < stack->array[0] && stack->array[0] < stack->array[1])
		ft_rev_rot(stack, c);
}

int	ft_find_min_idx(t_stack stack)
{
	int	i;
	int	idx;
	int	min;

	i = 0;
	idx = 0;
	min = stack.array[0];
	while (i < stack.size)
	{
		if (min > stack.array[i])
		{
			min = stack.array[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	ft_find_max_idx(t_stack stack)
{
	int	i;
	int	idx;
	int	max;

	i = 0;
	idx = 0;
	max = stack.array[0];
	while (i < stack.size)
	{
		if (max < stack.array[i])
		{
			max = stack.array[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

void	ft_top_and_push(t_stack *stack, int i, char c)
{
	while (i <= (stack->size - 1) / 2 && i > 0)
	{
		ft_rot(stack, c);
		i--;
	}
	while (i > (stack->size - 1) / 2 && i < stack->size)
	{
		ft_rev_rot(stack, c);
		i++;
	}
	if (c == A)
		ft_push(stack->other, B);
	else
		ft_push(stack->other, A);
}

void	ft_sort_up_to_5(t_prog *pg)	//Inutile?
{
	while (pg->a.size > 3)
		ft_top_and_push(&pg->a, ft_find_min_idx(pg->a), A);
	ft_sort_3(&pg->a, A);
	while (pg->b.size > 0)
		ft_push(&pg->a, A);
}

void	sort_tab(t_prog *pg)
{
	pg->sorted = ft_tabdup(pg->a.array, pg->a.size);
	ft_sort_int_tab(pg->sorted, pg->a.size);
}

int	find_closest_min(t_prog pg, t_stack stack, int chunk)
{
	int	i;
	int	from_top;
	int	from_bot;

	i = 0;
	from_top = -1;
	from_bot = -1;
	while (i < stack.size && from_top == -1)
	{
		if (stack.array[i] >= pg.sorted[pg.size / pg.chunk_nb * (chunk - 1)]
			&& (stack.array[i] <= pg.sorted[pg.size / pg.chunk_nb * chunk]
				|| chunk == pg.chunk_nb))
			from_top = i;
		// printf("----------\n");
		// printf("\nvaleur = %d\n", stack.array[i]);
		// printf("entre %d ", pg.sorted[pg.size / chunk_nb * (chunk - 1)]);
		// printf("et %d ?\n", pg.sorted[pg.size / chunk_nb * (chunk)]);
		// printf("fromtop =%d\n", from_top);
		i++;
	}
	i = stack.size - 1;
	while (i >= 0 && from_bot == -1)
	{
		if (stack.array[i] >= pg.sorted[pg.size / pg.chunk_nb * (chunk - 1)]
			&& (stack.array[i] <= pg.sorted[pg.size / pg.chunk_nb * chunk]
				|| chunk == pg.chunk_nb))
			from_bot = i;
		//printf("\nvaleur =%d\n", stack.array[i]);
		// printf("entre %d\n", pg.sorted[(pg.size / chunk_nb) * (chunk - 1)]);
		// printf("et %d\n", pg.sorted[(pg.size / chunk_nb) * (chunk)]);
		// printf("frombot =%d\n", from_bot);
		// printf("----------\n");
		i--;
	}
	//printf("fromtop = %d, frombot = %d\n", from_top, from_bot);
	if (from_top <= pg.size - from_bot)
		return (from_top);
	else
		return (from_bot);
}

void	ft_sort_up_to_500(t_prog *pg)
{
	int	chunk;
	int	i;

	chunk = 1;
	while (pg->a.size > 0)
	{
		i = find_closest_min(*pg, pg->a, chunk);
		if (i == -1 && chunk < pg->chunk_nb)
			chunk += 1;
		else
			ft_top_and_push(&pg->a, i, A);
		//ft_print_stacks(*pg);
	}
	while (pg->b.size > 0)
		ft_top_and_push(&pg->b, ft_find_max_idx(pg->b), B);
}

int	main(int ac, char **av)
{
	t_prog	*pg;
	char	**av2;

	pg = ft_calloc(1, sizeof(t_prog));
	if (ac < 2)
		ft_exit(0, 0);
	if (ac == 2)
	{
		av2 = ft_split(av[1], ' ');
		ac = ft_splitcount(av[1], ' ') + 1;
	}
	else
		av2 = &av[1];
	ft_char_check(ac, av2);
	convert(pg, ac, av2);
	pg->size = pg->a.size;
	pg->chunk_nb = 11 * (pg->size > 100) + 5 * (pg->size <= 100);
	pg->a.other = &pg->b;
	pg->b.other = &pg->a;
	ft_double_check(pg);
	ft_issorted(pg);
	sort_tab(pg);
	if (pg->size == 2)
		ft_swap(&pg->a, A);
	else if (pg->size <= 5)
		ft_sort_up_to_5(pg);
	else if (pg->size <= 500)
		ft_sort_up_to_500(pg);
	//ft_print_stacks(*pg);
	ft_exit(pg, 0);
}
