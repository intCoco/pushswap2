/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:36:11 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/08 19:35:02 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define A 'a'
# define B 'b'

typedef struct s_stack
{
	int 	*array;
	int		size;
	struct s_stack	*other;
	int		max;
	int		min;
}	t_stack;

typedef struct s_prog
{
	t_stack a;
	t_stack b;
	int		*sorted;
	int		max;
	int		min;
	int		size;
	int		chunk_nb;
}	t_prog;

/* void	ft_pa(t_prog *pg);
void	ft_pb(t_prog *pg);
void	ft_ra(t_prog *pg);
void	ft_rb(t_prog *pg);
void	ft_rra(t_prog *pg);
void	ft_rrb(t_prog *pg);
void	ft_sa(t_prog *pg);
void	ft_sb(t_prog *pg); */
void	ft_rot(t_stack *stack, char c);
void	ft_rev_rot(t_stack *stack, char c);
void	ft_swap(t_stack *stack, char c);
void	ft_push(t_stack *stack, char c);

#endif
