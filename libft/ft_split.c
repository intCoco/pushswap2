/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:28:45 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/07 14:14:25 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *src, int min, int max)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *) malloc((max - min) + 1);
	if (!dest)
		return (NULL);
	while (min < max)
	{
		dest[i] = src[min];
		min++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**res;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_splitcount(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		start = i++;
		while (!(s[i] == c && s[i - 1] != c) && s[i])
			i++;
		if (i != start && (s[i] == c || s[i] == '\0'))
			res[++j] = ft_strndup((char *)s, start, i);
		if (s[i] == c)
			i++;
	}
	res[ft_splitcount(s, c)] = 0;
	return (res);
}

/*int main()
{
	int i = 0;
	char **s = ft_split("                  olol", ' ');
	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
	printf("%s\n", s[i]);
}*/
