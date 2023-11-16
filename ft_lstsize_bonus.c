/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:34:23 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/15 22:24:17 by baouragh         ###   ########.fr       */
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
// int main()
// {

//     t_list *head;
//     t_list *tail;
//     t_list *to_up;
//     t_list *i;

//     int a = 1337;
//     int b = 42;
//     int c = 2004;

//     head = ft_lstnew(&a);
//     tail = ft_lstnew(&b);
//     to_up = ft_lstnew(&c);

//     head->next = tail;

//     ft_lstadd_front(&head,to_up);

//     i = head;

//     printf("%d\n",ft_lstsize(i));
//     while(i->next)
//     {
//         printf("%d\n",*(int *)i->content);
//         i = i->next;
//     }
// }
