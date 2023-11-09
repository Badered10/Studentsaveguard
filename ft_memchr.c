/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:52:05 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/08 18:16:23 by baouragh         ###   ########.fr       */
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
			return (ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = {0, 1, 2 ,3 ,4 ,5};
	char	*ptr;
	char	*ptr2;

	ptr = memchr(s, 2 + 256, 3);
	ptr2 = ft_memchr(s, 2 + 256, 3);
	printf("org %s , copy %s\n",ptr,ptr2);
}
*/