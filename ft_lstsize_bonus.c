/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:34:23 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:39:16 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	res;

	res = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		res++;
	}
	return (res);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*tail;
	t_list	*to_up;
	int		a;
	int		b;
	int		c;

	a = 1;
	b = 2;
	c = 3;
	head = ft_lstnew(&a);
	tail = ft_lstnew(&b);
	to_up = ft_lstnew(&c);
	head->next = tail;
	ft_lstadd_front(&head,to_up);
	printf("%d\n",ft_lstsize(head));
	while(head->next)
	{
		printf("%d\n",*(int *)head->content);
		head = head->next;
	}
}
*/
