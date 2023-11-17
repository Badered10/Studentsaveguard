/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:54:08 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:37:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new;
	char	*c1;
	char	*c2;
	char	*c3;
	char	*c4;

	c1 = "hello\n";
	c2 = "world\n";
	c3 = "bader\n";
	c4 = "i am the one\n";
	node1 = ft_lstnew(c1);
	node2 = ft_lstnew(c2);
	node3 = ft_lstnew(c3);
	new = ft_lstnew(c4);
	node1->next = node2;
	node2->next = node3;
	ft_lstadd_front(&node1,new);
	while(node1)
	{
		printf("%s",(char*)node1->content);
		node1 = node1->next;
	}
}
*/
