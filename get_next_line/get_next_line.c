/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/20 12:14:20 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *get_next_line(int fd)
{
    read(fd,,BUFFER_SIZE);
}
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    close(fd);
    int x = atoi("23");
    printf("%d",x);
}