/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:26:03 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/27 13:27:55 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	char	*tmp;

	tmp = (char *)s;
	while (*s++)
		;
	s -= 1;
	return (s - tmp);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (!destination && !source)
		return (NULL);
	if (destination == source)
		return (dst);
	while (n--)
		*destination++ = *source++;
	return (dst);
}
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (len != 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return ((void *)destination);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	lenth;
    
    if (!s1)
    return(ft_strdup(""));
	lenth = ft_strlen(s1);
	copy = (char *)malloc(lenth + 1);
	if (!copy)
		return (NULL);
	ft_memmove(copy, s1, lenth);
	copy[lenth] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
    if (!s1)
    return(ft_strdup(s2));
    if (!s2)
    return(ft_strdup(s1));
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	ft_memmove(new, s1, ft_strlen(s1));
	ft_memmove(new + ft_strlen(s1), s2, ft_strlen(s2));
    new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (new);
}
