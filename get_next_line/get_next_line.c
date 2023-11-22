/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/22 19:04:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	int i;
 
    i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*source;
	size_t	source_lenth;
    int i;
    
    i = 0;
	source = (char *)src;
    while(source[i] != '\n' && source[i] != '\0')
    i++;
	source_lenth = i;
    
	if (dstsize == 0)
		return (source_lenth);
	dstsize -= 1;
	while ((dstsize > 0) && *source)
	{
		*dst++ = *source++;
		if (dstsize != 0)
			dstsize--;
	}
	*dst = '\0';
	return (source_lenth);
}

t_list *new_node(char *s)
{
    t_list *new;
    if (!s)
    return NULL;
    new = malloc(sizeof(t_list));
    if (!new)
    return NULL;
    new->text = malloc(ft_strlen(s) + 1);
    if (!new->text)
    return NULL;
    ft_strlcpy(new->text ,s,ft_strlen(s) + 1);
    new->next = NULL;
    return (new);
}

t_list *ft_last(t_list *node)
{
    t_list *res;
    if (!node)
    return(NULL);
    while(node)
    {
        res = node;
        node = node->next;
    }
    return (res);
}

void ft_clean(t_list **list)
{
    t_list *tmp;
    char *iter;
    char *str;
    if (!list)
    return ;

    int i = 0;
    int n = 0;
    tmp = ft_last((*list));
    iter = tmp->text;
    while (iter[i] != '\n' && iter[i] != '\0')
        i++;
    while(iter[i + n] != '\0')
        n++;
    str = malloc(sizeof(char) * n + 1);
    strlcpy(str, iter + i , n + 1);
    free(*list);
    (*list) = new_node(str);
}

void add_back(t_list **list, t_list *new)
{
    t_list *tmp;
    if (!list || !new)
    return;
    if (!*list)
    {
        *list = new;
        return;
    }
    tmp = ft_last(*list);
    tmp->next = new;
}

char *alloc_for_me(t_list *list)
{
    char *final;
    size_t i;
    i  = 0;
    t_list *tmp;
    size_t ok;
    ok  = 0;
    tmp = list;
    while(tmp)
    {
        i += ft_strlen(tmp->text);
        tmp = tmp->next;
    }
    final = malloc(sizeof(char) * i);
    while(list)
    {
        ft_strlcpy(final + ok,list->text,ft_strlen(list->text));
        ok += ft_strlen(list->text);
        list = list->next;
    }
    final[ok - 1] = '\0';
    return(final);
    
}

void my_list(t_list **list,int fd,size_t size)
{
    char buffer[BUFFER_SIZE];
    size_t byets_readed;
    t_list *new;
    
    if (!*list)
    {
        byets_readed = read(fd,buffer,BUFFER_SIZE);
        if (!byets_readed)
        return;
        *list = new_node(buffer);
        if(*list)
        return;
    }

    while(!n_finder((*list)->text))
    {
        byets_readed = read(fd,buffer,BUFFER_SIZE);
        if (!byets_readed)
        return;
        new = new_node(buffer);
        if(*list)
        return;
        add_back(&(*list), new);
    }
}

char *get_next_line(int fd)
{
    static t_list *list;
    char * next_line;

    list = (NULL);
        
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,&next_line,0) < 0)
    return NULL;
    my_list(&list,fd,BUFFER_SIZE);
    if(list)
    next_line = alloc_for_me(list);
   ft_clean(&list);
   return (next_line);
}

int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    char *str;
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    str = get_next_line(fd);
    printf("%s\n",str);
    close(fd);
}