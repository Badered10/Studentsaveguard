/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:11:27 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/09 11:41:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (!n)
		return (0);
	while (n - 1 > 0 && s1[i] - s2[i] == 0 && s1[i] && s2[i])
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	size;
	int		x;
	int		x1;

	s1 = "atoms\0\0\0\0";
	s2 = "atomsabc";
	size = 0;
	x = ft_strncmp(s1, s2, size);
	x1 = strncmp(s1, s2, size);
	printf("x =%d\t x1=%d\n", x, x1);
}
*/
