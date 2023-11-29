/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:18 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/26 18:39:08 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


t_list	*ft_last(t_list *node)
{
	t_list	*res;

	if (!node)
	return node;
	printf("node addres is :%p\n",node);
	printf("before fucked up %s\n",node->text);
	while (node)
	{
		res = node;
		node = node->next;
	}
	return (res);
}
int	n_finder(t_list *list)
{
	printf("-----------------------------nfinder--------------------------------");
	int	i;
	t_list *last;

	i = 0;
	printf("--------------list adress in n_finder %p---------------------\n",list);
	if (!list)
	{
		printf("list empty in n finder \n");
	return 0;
	}
	last = ft_last(list);
	printf("--------------list adress in n_finder %p---------------------\n",last);
	while (last->text[i])
	{
		while (last->text[i] != '\n' && last->text[i] != '\0')
		{
			printf(" i scan for /0 /n is :%d\n",i);
			i++;
		}
		if (last->text[i] == '\n' || last->text[i] == '\0')
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

	if (!dst || !src || !dstsize)
	return;
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
	printf("i am in new node -------------------------\n");
	t_list	*new;
	t_list	*last;
	
	printf("---- bufer : %s\n ",buffer);
	if (!buffer)
		return ;
	last = ft_last((*list));
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
	{
		printf("ONE________________\n");	
		(*list) = new;
	}
	else
	{
		printf("TWO________________\n");
		(*list)->next = new;
	}
	new->text = buffer;
	printf("---- new->text bufer : %s\n ",new->text);
	new->next = NULL;
}
void	ft_clean(t_list **list, char *rest, t_list *next_node)
{
	printf("i am in clean -------------------------\n");
	t_list	*tmp;

	printf("rest in clean is :%s\n",rest);
	while ((*list) != NULL)
	{
		printf("1\n");
		tmp = (*list)->next;
		free((*list)->text);
        free((*list));
		*list = tmp;
	}
	if(rest[0]== '\0')
	{
		printf("when last node have 0 it freed !!\n");
		free(rest);
		free(next_node);
		(*list) = NULL;
	}
	else
	{
		(*list) = next_node;
	}
}
void 	ft_nextnode(t_list **list)
{
		printf("i am in ft_next_node-----------------------\n");
	t_list	*last;
	t_list	*next_node;
	char	*rest;
	int		i;
	int		nplace;

	i = 0;
	nplace = 0;
	if (!list || !*list)
		return ;

	next_node = malloc(sizeof(t_list));
	last = ft_last(*list);
	printf("in fclean last->text : %s\n",last->text);
	if (n_finder(last))
	{
	while ((last)->text[i] != '\n' && (last)->text[i] != '\0')
		i++;
		printf("i = %d\n",i);
				
	while ((last)->text[nplace + i] != '\0')
		nplace++;
		printf("nplace = %d\n",nplace);
		
	}
	rest = malloc(sizeof(char) * nplace + 1);
    if (!rest)
    return;
	strlcpy(rest, &(last)->text[i], nplace + 1);
	printf("rest is '%s'\n",rest);
	next_node->text = rest;
	next_node->next = NULL;
	printf("next_node->text is '%s'\n",next_node->text);
	ft_clean(&(*list),rest,next_node);
}
char	*ft_fill(t_list **list, char *res)
{
	printf("i am in ft_fill-----------------------\n");
	int	i;
	int	total;

	if (!(*list))
	return (NULL);

	total = 0;
	printf("text holded by list :%s\n",(*list)->text);
	while ((*list))
	{
		printf("im in fill loop \n");
		i = 0;
		while ((*list)->text[i] != '\0')
		{
			printf("total is :%d\t",total);
			printf("i is : %d\n",i);
			res[total] = (*list)->text[i];
			if ((*list)->text[i + 1] == '\n' || (*list)->text[i + 1] == '\0' )
			{
				if((*list)->text[i] == '\n')
				{	
				res[total] = '\n';
				res[total + 1] = '\0';
				}
				else if ((*list)->text[i] == '\0')
					res[total] = '\0';
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
	printf("i am in alloc_forme-----------------------\n");
	t_list	*tmp;
	char	*res;
	int		total;
	int		i;

	if (!(*list))
	return (NULL);
	
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
	printf("TOTAL CHECK IN ALLOC %d\n",total + 1 );
    if(!res)
    return (NULL);
	return (ft_fill(&(*list), res));
}


int	my_list(t_list **list, int fd)
{
	printf("i am in my-list-----------------------\n");
	char	*buffer;
	int		byets_readed;

	while (!n_finder(*list))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
		return(-1);
		byets_readed = read(fd, buffer, BUFFER_SIZE);
			printf(" --------------------------------------byets readed %d\n",byets_readed);
		if (byets_readed  <= 0)
		{
			free(buffer);
			return(byets_readed);
		}
			buffer[byets_readed] = '\0';
			new_node(&(*list),buffer);
	}
	return(byets_readed);
}
char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int check;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		printf("file invalid!\n");
		return (NULL);
	}
	check = my_list(&list, fd);
    if (!list || check  <= 0)
	{
		printf("empty list or byets readed is 0\n");
    return (NULL);
	}
		next_line = alloc_for_me(&list);
		ft_nextnode(&list);
	return (next_line);
}
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDONLY, 0777);
    char *str;
	int i =  0;
	while (i++ < 20)
	{
    str = get_next_line(fd);
    printf("-----in main %s----",str);
		
	}
    close(fd);
}