/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:52:05 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/03 20:52:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *ptr;
	ptr = (char *)s;
	while (n-- && ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}