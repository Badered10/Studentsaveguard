/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/21 22:11:44 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void my_list(t_list **list,int fd)
{
    
}

t_list *new_node(char *s,size_t byets)
{
    t_list *new;
    if (!s)
    return NULL;
    new = malloc(sizeof(t_list));
    new->text = s;
    new->next = NULL;
    return (new);
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
    char * next_line;
        
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,&next_line,0) < 0)
    return NULL;
    my_list(&list,fd);
    
}
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    char *str;
    str = get_next_line(fd);
    printf("%s\n",str);
    close(fd);
}