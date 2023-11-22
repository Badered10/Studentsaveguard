/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/22 10:17:50 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	char	*tmp;

	tmp = (char *)s;
	while (*s++)
		;
	s -= 1;
	return (s - tmp);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*source;
	size_t	source_lenth;

    if (!dst || !src)
        return(NULL);

	source = (char *)src;
	source_lenth = ft_strlen(source);
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


char *alloc_for_me(t_liat *list)
{
    size_t 
    while(list)
    {
        ft_strlen(list->text);
        list = list->next;
    }
}

t_list *last(t_list *node)
{
    t_list *res;
    if (!node)
    return(NULL);
    while(node)
    {
        node = res;
        node = node->next;
    }
    return (res);
}

void add_back(t_list **list, t_list *new)
{
    t_list *tmp;
    if (!list || !new)
    return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = last(*lst);
    tmp->next = new;
}

t_list *new_node(char *s,size_t byets_readed)
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
    ft_strlcpy(new->next,s,ft_strlen(s) + 1)
    new->next = NULL;
    return (new);
}

void my_list(t_list **list,int fd)
{
    char buffer[BUFFER_SIZE];
    size_t byets_readed;
    
    while (!n_finder((*list)->text))
    {
        byets_readed = read(fd,buffer,BUFFER_SIZE);
        if (!byets_readed)
        return;
        *list = new_node(buffer,byets_readed);
        add_back(*list);
    }
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

    list = (NULL);
        
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