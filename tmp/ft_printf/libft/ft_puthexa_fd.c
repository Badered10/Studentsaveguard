/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:20:43 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/14 10:21:09 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa_fd(unsigned int res , int fd ,char ch)
{
	int count;
	char *str;

	count = 0;
	if ((fd < 0))
		return (-1);
	str = ft_itohexa(res, ch);
	if(!str)
	return 0;
	count += write(fd, str, ft_strlen(str));
	if (res == 0)
		count += write(1,"0",1);
	free(str);
	return (count);
}