/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:00:26 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:20 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

// int main()
// {
// 	int arr[] = { 42,34,547,235};
// 	ft_memset(&arr[2],5,2);
// 	ft_memset(&arr[2],57,1);
// 	printf("%d",arr[2]);
// }