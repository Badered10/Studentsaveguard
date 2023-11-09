/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:28:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/09 11:38:27 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ocean;
	char	*fish;

	ocean = (char *)haystack;
	fish = (char *)needle;
	if (!needle)
		return (ocean);
	while (len-- && *ocean)
	{
		while ((*fish && *ocean) && (*ocean == *fish))
		{
			ocean++;
			fish++;
		}
		if (!*fish)
			return (ocean -= ft_strlen(needle), ocean);
		fish = (char *)needle;
		ocean++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*big;
	char	*little;
	size_t	max;
	char	*s1;
	char	*s2;

	big = "abcdef";
	little = "abcdefghijklmnop";
	max = strlen(big);
	s1 = strnstr(big, little, max);
	s2 = ft_strnstr(big, little, max);
}
*/