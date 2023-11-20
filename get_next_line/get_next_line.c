/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/20 16:17:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *alloc(char *s)
{
    char *res;
    int i;

    i = 0;
    while(s[i] != '\n')
        i++;
        
    res = ft_calloc(sizeof(char) * i);
    ft_memmove(res,s,i);
    return (res);
}

int n_finder(char *s)
{
    int i;

    i  = 0;
    while(s[i] != '\0')
    {
        while(s[i] != '\n')
        i++;
        if(s[i] == '\n')
        return (1);
    }
    return (0);
}

char *get_next_line(int fd)
{
    static t_list *list;
    char *data;
    size_t byets;
        
    if (fd < 0 )
    return NULL;
    byets = read(fd,data,BUFFER_SIZE);
    if (byets < 0)
    return NULL;
    if(n_finder(data) == 1)
        return(alloc(data));
}
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    close(fd);
}