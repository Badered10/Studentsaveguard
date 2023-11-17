/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:49:44 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:38:31 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void	ok(void *content)
{
	char	*str;

	str = (char*)content;
	while(*str)
	{
		*str -= 32;
		str++;
	}
}

int	main(void)
{
	t_list	*node;
	t_list	*node1;
	t_list	*node2;
	char	str1[] = "hello";
	char	str2[] = "oekey";
	char	str3[] = "done";

	node = ft_lstnew(str1);
	node1 = ft_lstnew(str2);
	node2 = ft_lstnew(str3);
	node->next = node1;
	node1->next = node2;
	ft_lstiter(node,ok);
	while(node)
	{
		printf("%s\n",(char*)node->content);
		node = node->next;
	}
}
*/