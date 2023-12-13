/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:31:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 14:31:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(void *s, int fd,)
{
	int count;

	count = 0;
	if ((fd < 0) || !s)
		return (-1);
	count += write(fd, s, ft_strlen(s));
	return (count);
}