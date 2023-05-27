/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:31:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/07 14:15:50 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_splitcount(const char *s, char c)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	len = 0;
	while (s[i])
	{
		start = i++;
		while (!(s[i] == c && s[i - 1] != c) && s[i])
			i++;
		if (i != start && (s[i] == c || s[i] == '\0'))
			len++;
		if (s[i] == c)
			i++;
	}
	return (len);
}
