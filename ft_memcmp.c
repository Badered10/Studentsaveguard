/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:54:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 21:34:34 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*b1;
	const unsigned char	*b2;

	b1 = (const unsigned char *)s1;
	b2 = (const unsigned char *)s2;
	if (!n)
		return (0);
	while ((--n != 0) && ((unsigned char)*b1 - (unsigned char)*b2 == 0))
	{
		b1++;
		b2++;
	}
	return ((unsigned char)*b1 - (unsigned char)*b2);
}
/*
#include <string.h>

int	main(void)
{
	const char	*b1 = NULL;
	const char	*b2 = "asasd";
	int			y;

	// int x = ft_memcmp(b1,b2,8);
	y = ft_memcmp(b1,b2,0);
	printf("%d ------",y);
}
*/