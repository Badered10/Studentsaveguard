/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:54:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/15 23:38:18 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*b1;
	const unsigned char	*b2;

	b1 = (const unsigned char *)s1;
	b2 = (const unsigned char *)s2;
	n -= 1;
	while (n-- > 0 && (unsigned char)*b1 - (unsigned char)*b2 == 0)
	{
		b1++;
		b2++;
	}
	return ((unsigned char)*b1 - (unsigned char)*b2);
}