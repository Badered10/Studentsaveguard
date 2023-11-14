/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:18:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/13 09:50:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **res, int words)
{
	while (words > 0)
	{
		words--;
		free(res[words]);
	}
	free(res);
	return (NULL);
}

static int	ft_wcounter(const char *s, char c)
{
	char	*x;
	int		words;

	words = 0;
	x = (char *)s;
	while (*x)
	{
		while (*x == c && *x)
			x++;
		if (*x)
		{
			while (*x != c && *x)
				x++;
			words++;
		}
	}
	return (words);
}

static char	**realone(char **res, char const *s, char c, int words)
{
	char	*p;
	char	*start;
	int		initial;

	initial = ft_wcounter(s, c);
	p = (char *)s;
	while (words--)
	{
		while (*p == c)
			p++;
		start = p;
		while (*p != c && *p)
			p++;
		*res = ft_substr(start, 0, p - start);
		if (!*res)
			return (ft_free(res, (initial - words)));
		res++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = ft_wcounter(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res = realone(res, s, c, words);
	if (!res)
		return (NULL);
	*res = NULL;
	words = ft_wcounter(s, c);
	return (res - words);
}

// int	main(void)
// {
// 	const char	*s = "hello!";
// 	char		c;
// 	char		**k;
// 	int			i;
// 	int			words;

// 	c = ' ';
// 	k = ft_split(s, c);
// 	i = 0;
// 	words = ft_wcounter(s, c);
// 	while (i < words)
// 	{
// 		printf("%s\n", k[i]);
// 		i++;
// 	}
// }

// if (*res == NULL)
// {
// 	while (words-- > 0)
// 		free(res[words - 1]);
// 	free(res);
// 	return (NULL);
// }