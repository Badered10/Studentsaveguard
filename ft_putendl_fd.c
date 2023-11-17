/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:04:56 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 23:16:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_putendl_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
    write(fd, "\0", 1);
}


int main()
{
  char s[]="hello";
  write(1, s, ft_strlen(s));
  write(1, , 1);
  write(1, s, ft_strlen(s));
}