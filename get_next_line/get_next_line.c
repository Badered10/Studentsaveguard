/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/23 23:44:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_finder(char *s, int byets_readed)
{
	int	i;

	i = 0;
	while (byets_readed)
	{
		while (s[i] != '\n' && byets_readed)
		{
			byets_readed--;
			i++;
		}
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*source;
	int		i;

	i = 0;
	source = (char *)src;
	dstsize -= 1;
	while ((dstsize > 0) && *source)
	{
		*dst++ = *source++;
		if (dstsize != 0)
			dstsize--;
	}
	*dst = '\0';
}

t_list	*new_node(char *s, int byets_readed)
{
	t_list	*new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->text = malloc(byets_readed + 1);
	if (!new->text)
		return (NULL);
	ft_strlcpy(new->text, s, byets_readed + 1);
	new->next = NULL;
	return (new);
}

t_list	*ft_last(t_list *node)
{
	t_list	*res;

	if (!node)
		return (NULL);
	while (node)
	{
		res = node;
		node = node->next;
	}
	return (res);
}

void	add_back(t_list ***list, t_list *new)
{
	t_list	*tmp;

	if (!list || !new)
		return ;
	if (!*(*list))
	{
		*(*list) = new;
		return ;
	}
	tmp = *(*list);
	tmp = ft_last(*(*list));
	tmp->next = new;
}

char	*ft_fill(t_list *list, char *res)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (list)
	{
		while (list->text[i] != '\0')
		{
			res[total] = list->text[i];
			if (list->text[i] == '\n')
			{
				res[total] = '\n';
				res[total + 1] = '\0';
				break ;
			}
			i++;
			total++;
		}
		i = 0;
		list = list->next;
	}
	return (res);
}

char	*alloc_for_me(t_list *list)
{
	t_list	*tmp;
	char	*res;
	int		total;
	int		i;

	i = 0;
	total = 0;
	tmp = list;
	while (tmp)
	{
		while (tmp->text[i] != '\0')
		{
			if (tmp->text[i] == '\n')
				break ;
			i++;
			total++;
		}
		i = 0;
		tmp = tmp->next;
	}
	res = malloc(sizeof(char) * total + 2);
    if(!res)
    return (NULL);
	return (ft_fill(list, res));
}

void	my_list(t_list **list, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		byets_readed;
	t_list	*new;
	t_list	*tmp;

	while (1)
	{
		byets_readed = read(fd, buffer, BUFFER_SIZE);
		if (!byets_readed)
			return ;
		new = new_node(buffer, byets_readed);
		add_back(&list, new);
		tmp = ft_last(*list);
		if (n_finder(tmp->text, byets_readed) != 0)
			break ;
	}
}

t_list	*ft_clean(t_list **list)
{
	t_list	*tmp;
	t_list	*last;
	char	*rest;
	int		i;
	int		nplace;

	i = 0;
	nplace = 0;
	if (!list || !*list)
		return (NULL);
	last = ft_last(*list);
	while (*list != last)
	{
		tmp = (*list)->next;
		free((*list)->text);
		free((*list));
		*list = tmp;
	}
	while ((last)->text[i])
		i++;
	while (n_finder((last)->text, i) && ((last)->text[nplace] != '\n'))
		nplace++;
	rest = malloc(sizeof(char) * i + 1);
	strlcpy(rest, &(last)->text[nplace + 1], i + 1);
	last = new_node(rest, i + 1);
	free(rest);
	return (last);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	my_list(&list, fd);
    if (!list)
    return (NULL);
		next_line = alloc_for_me(list);
	list = ft_clean(&list);
	return (next_line);
}

// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     char *str;
//     str = get_next_line(fd);
//     printf("%s",str);
//     str = get_next_line(fd);
//     printf("%s",str);
//     str = get_next_line(fd);
//     printf("%s",str);
//     close(fd);
// }