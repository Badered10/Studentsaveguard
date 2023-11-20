/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:52:05 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/18 16:01:20 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	if (c == 0 && n > ft_strlen(ptr))
		return (ptr + ft_strlen(ptr));
	while (n)
	{
		if (ptr[i] == (char)c)
			return ((void *)ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
