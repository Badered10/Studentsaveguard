/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:41:50 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/16 13:35:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *tmp;

    tmp = NULL;
    if(!lst)
    return NULL;
    while(lst)
    {
        tmp = lst;
        lst = lst->next;
    }
    return(tmp);
}

// int main(void)
// {
//     t_list *head;
//     t_list *ok;
//     int x;

//     head = ft_lstnew("hello");
//     ok = ft_lstlast(head);
//     x = ft_lstsize(head);
//     printf("%s and size is :%d",(char*)ok->content,x);
// }