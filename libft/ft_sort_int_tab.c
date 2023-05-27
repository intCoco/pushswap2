/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:04:02 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/08 19:51:56 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	s;

	s = 0;
	i = 1;
	while (s < size - 1)
	{
		while (i < size)
		{
			if (tab[s] > tab[i])
			{
				ft_swap_ptr(&tab[i], &tab[s]);
				i = s + 1;
			}
			else
				i++;
		}
		s++;
		i = s + 1;
	}
}
