/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:50:13 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/08 12:32:47 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_bzero(void *b, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)b;
	i = 0;
	while (i < n)
	{
		ft_memset(&str[i], 0, sizeof(char));
		i++;
	}
}
*/
void	ft_bzero(void *b, size_t n)
{
	ft_memset(b, 0, n);
}
