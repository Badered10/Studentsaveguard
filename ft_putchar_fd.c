/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:52:01 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 23:51:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <fcntl.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
int main()
{
    int fd = open("test.txt",O_RDWR | O_CREAT);
    ft_putchar_fd('d',fd);
    printf("File Descriptor: %d\n", fd);
}