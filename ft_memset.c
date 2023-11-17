/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:00:26 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:39:37 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)b;
	i = 0;
	while (i < len)
		temp[i++] = c;
	return (b);
}

/*
#include <stdio.h>

int	main(void)
{
	int	arr[] = {5,6,8,9};

	ft_memset(&arr[0],0,1);
	ft_memset(&arr[0],120,1);
	printf("%d",arr[0]);
}
*/