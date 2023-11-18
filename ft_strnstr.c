/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:28:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/18 17:22:47 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ocean;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!len && !haystack)
		return (NULL);
	ocean = (char *)haystack;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len)
	{
		while ((haystack[i + j] == needle[j]) && (haystack[i] && needle[j])
			&& j < len)
			j++;
		if (needle[j])
			len--;
		if (needle[j] == '\0')
			return (ocean + i);
		i++;
		j = 0;
	}
	return (NULL);
}
