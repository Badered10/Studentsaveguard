/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:55 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 22:37:37 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = (*lst);
	tmp = ft_lstlast(tmp);
	tmp->next = new;
}

/*
int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*last;
	t_list	*tmp;

	first  = ft_lstnew("one");
	second = ft_lstnew("two");
	third  = ft_lstnew("three");
	last   = ft_lstnew("and four");
	first->next = second;
	second->next = third;
	tmp = first;
	ft_lstadd_back(&first,last);
	while(tmp)
	{
		printf("%s\n",(char*)tmp->content);
		tmp = tmp->next;
	}
}
*/