/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/24 11:40:04 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
int	n_finder(t_list *list)
{
	int	i;
	t_list *last;

	i = 0;
	// printf("--------------list adress in n_finder %p\n",list);
	if (!list)
	{
		// printf("i am here \n");
	return 0;
	}
	last = ft_last(list);
	// printf("--------------last in n_finder %p\n",last);
	while (last->text[i])
	{
		while (last->text[i] != '\n' && last->text[i] != '\0')
		{
			// printf("%d\n",i);
			i++;
		}
		if (last->text[i] == '\n')
		{
			// printf("BINGO \n");
			return (1);
		}
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


void	new_node(t_list **list,char *buffer)
{
	t_list	*new;
	t_list	*last;
	
	// printf("---- bufer : %s\n ",buffer);
	if (!buffer)
		return ;
	last = ft_last((*list));
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
	{
		// printf("ONE________________\n");	
		(*list) = new;
	}
	else
	{
		// printf("TWO________________\n");
		(*list)->next = new;
	}
	new->text = buffer;
	// printf("---- new->text bufer : %s\n ",new->text);
	new->next = NULL;
}

void	ft_clean(t_list **list)
{
	// printf("i am in ft_clean-----------------------\n");
	t_list	*tmp;
	t_list	*last;
	char	*rest;
	int		i;
	int		nplace;

	i = 0;
	nplace = 1;
	if (!list || !*list)
		return ;
	last = ft_last(*list);
	// printf("in fclean last->text : %s\n",last->text);
	if (n_finder(last))
	{
	while ((last)->text[i] != '\n' && (last)->text[i] != '\0')
		i++;
		
	while ((last)->text[nplace + i] != '\n' && (last)->text[nplace + i] != '\0')
		nplace++;
	}
	rest = malloc(sizeof(char) * nplace + 1);
    if (!rest)
    return;
	strlcpy(rest, &(last)->text[i + 1], nplace + 1);
	while (*list != NULL)
	{
		tmp = (*list)->next;
		free((*list)->text);
        free((*list));
		*list = tmp;
	}
	// printf("-------------------rest:%s\n",rest);
	new_node(&(*list),rest);
	// printf("Last check for text in list to next time : %s\n",(*list)->text);
}
char	*ft_fill(t_list **list, char *res)
{
	// printf("i am in ft_fill-----------------------\n");
	int	i;
	int	total;

	total = 0;
	// printf("text holded by list :%s\n",(*list)->text);
	while ((*list))
	{
		i = 0;
		while ((*list)->text[i] != '\0')
		{
			res[total] = (*list)->text[i];
			if ((*list)->text[i] == '\n')
			{
				res[total] = '\n';
				res[total + 1] = '\0';
				// printf("my fresh next line check -------->%s\n",res);
				return (res);
			}
			i++;
			total++;
		}
		(*list) = (*list)->next;
	}
	return (NULL);
}

char	*alloc_for_me(t_list **list)
{
	// printf("i am in alloc_forme-----------------------\n");
	t_list	*tmp;
	char	*res;
	int		total;
	int		i;

	total = 0;
	tmp = (*list);
	while (tmp)
	{
		i = 0;
		while (tmp->text[i] != '\0')
		{
			if (tmp->text[i] == '\n')
			{
				total++;
				break ;
			}
			i++;
			total++;
		}
		tmp = tmp->next;
	}
	res = malloc(sizeof(char) * total + 1);
	// printf("TOTAL CHECK IN ALLOC %d\n",total + 1 );
    if(!res)
    return (NULL);
	return (ft_fill(&(*list), res));
}


void	my_list(t_list **list, int fd)
{
	char	*buffer;
	int		byets_readed;

	while (!n_finder(*list))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
		return;
		byets_readed = read(fd, buffer, BUFFER_SIZE);
			// printf(" %d\n",byets_readed);
		if (!byets_readed)
		{
			free(buffer);
			return ;
		}
			buffer[byets_readed] = '\0';
			new_node(&(*list),buffer);
	}
}
char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	my_list(&list, fd);
    if (!list)
	{
		// printf("YESS its me !!!");
    return (NULL);
	}
		next_line = alloc_for_me(&list);
		ft_clean(&list);
	return (next_line);
}
// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     char *str;
//     str = get_next_line(fd);
//     printf("______________finish______%s________\n",str);
// 	str = get_next_line(fd);
//      printf("______________finish______%s________\n",str);
//     close(fd);
// }