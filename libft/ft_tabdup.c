/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:26:22 by chuchard          #+#    #+#             */
/*   Updated: 2023/06/19 18:05:24 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_tabdup(int *tab, int size)
{
	int	i;
	int	*tab2;

	i = -1;
	tab2 = ft_calloc(sizeof(int), size);
	while (++i < size)
		tab2[i] = tab[i];
	return (tab2);
}
