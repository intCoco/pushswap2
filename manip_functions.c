/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:22:42 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/08 16:29:10 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack, char c)
{
	int	tmp;
	
	if (!stack->other)
		return ;
	stack->size++;
	stack->other->size--;
	tmp = stack->other->array[0];
	ft_memmove(stack->other->array, stack->other->array + 1, stack->other->size * sizeof(int));
	ft_memmove(stack->array + 1, stack->array, stack->size * sizeof(int));
	stack->array[0] = tmp;
	ft_printf("p%c\n", c);
}

void	ft_rot(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	ft_memmove(stack->array, stack->array + 1, stack->size * sizeof(int));
	stack->array[stack->size - 1] = tmp;
	ft_printf("r%c\n", c);
}

void	ft_rev_rot(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	ft_memmove(stack->array + 1, stack->array, stack->size * sizeof(int));
	stack->array[0] = tmp;
	ft_printf("rr%c\n", c);
}

void	ft_swap(t_stack *stack, char c)
{
	int	tmp;
	
	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	ft_printf("s%c\n", c);
}

/* void	ft_pa(t_prog *pg)
{
	int		i;
	int		tmp;
	
	if (pg->b.size == 0)
		return ;
	i = 0;
	tmp = pg->b.array[0];
	while (++i < pg->a.size + 1)
		pg->a.array[i] = pg->a.array[i - 1];
	pg->a.size++;
	pg->a.array[0] = tmp;
	i = -1;
	while (++i < pg->b.size - 1)
		pg->b.array[i] = pg->b.array[i + 1];
	pg->b.size--;
	ft_printf("pa\n");
}

void	ft_pb(t_prog *pg)
{
	int		i;
	int		tmp;
	
	if (pg->a.size == 0)
		return ;
	i = 0;
	tmp = pg->a.array[0];
	while (++i < pg->b.size + 1)
		pg->b.array[i] = pg->b.array[i - 1];
	pg->b.size++;
	pg->b.array[0] = tmp;
	i = -1;
	while (++i < pg->a.size - 1)
		pg->a.array[i] = pg->a.array[i + 1];
	pg->a.size--;
	ft_printf("pb\n");
}

void	ft_ra(t_prog *pg)
{
	int	tmp;
	int	i;

	if (pg->a.size < 2)
		return ;
	tmp = pg->a.array[0];
	i = -1;
	while (++i < pg->a.size - 1)
		pg->a.array[i] = pg->a.array[i + 1];
	pg->a.array[++i] = tmp;
	ft_printf("ra\n");
}

void	ft_rb(t_prog *pg)
{
	int	tmp;
	int	i;

	if (pg->b.size < 2)
		return ;
	tmp = pg->b.array[0];
	i = -1;
	while (++i < pg->b.size - 1)
		pg->b.array[i] = pg->b.array[i + 1];
	pg->b.array[++i] = tmp;
	ft_printf("rb\n");
}

void	ft_rra(t_prog *pg)
{
	int	tmp;
	int	i;

	if (pg->a.size < 2)
		return ;
	i = pg->a.size;
	tmp = pg->a.array[i - 1];
	while (--i > 0)
		pg->a.array[i] = pg->a.array[i - 1];
	pg->a.array[0] = tmp;
	ft_printf("rra\n");
}

void	ft_rrb(t_prog *pg)
{
	int	tmp;
	int	i;

	if (pg->b.size < 2)
		return ;
	i = pg->b.size;
	tmp = pg->b.array[i - 1];
	while (--i > 0)
		pg->b.array[i] = pg->b.array[i - 1];
	pg->b.array[0] = tmp;
	ft_printf("rrb\n");
}

void	ft_sa(t_prog *pg)
{
	int	tmp;

	if (pg->a.size < 2)
		return ;
	tmp = pg->a.array[0];
	pg->a.array[0] = pg->a.array[1];
	pg->a.array[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_prog *pg)
{
	int	tmp;

	if (pg->b.size < 2)
		return ;
	tmp = pg->b.array[0];
	pg->b.array[0] = pg->b.array[1];
	pg->b.array[1] = tmp;
	ft_printf("sb\n");
} */

/*void	ft_rot(t_link *stack)
{
	int	top;

	top = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = top;
}*/

/*void	ft_push(t_link *src_top, t_link *dest_top)
{
	t_link *next;

	if (src_top)
	{
		next = src_top->next;
		ft_lstadd_front(dest_top, src_top);
		*src_top = *next;
	}
}*/

/*void	ft_push(t_stack *src, t_stack *dest, char c)
{
	int		i;
	int		tmp;
	
	if (src->size == 0)
		return ;
	i = 0;
	tmp = src->array[0];
	while (++i < dest->size + 1)
		dest->array[i] = dest->array[i - 1];
	dest->size++;
	dest->array[0] = tmp;
	i = -1;
	while (++i < src->size - 1)
		src->array[i] = src->array[i + 1];
	src->size--;
	ft_printf("p%c\n", c);
}*/
