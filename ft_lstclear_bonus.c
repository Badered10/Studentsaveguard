/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:19:09 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 14:29:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *tmp;

    if (!lst  || !del)
    return ;
    while (*lst)
    {
       tmp = (*lst)->next;
       ft_lstdelone((*lst),del);
       *lst = tmp;
    }
}
// void delet(void *lst)
// {
//     free(lst);
// }
// int main()
// {
//     t_list *head;
//     t_list *ok;
//     t_list *dude;

    
//     head = ft_lstnew("hello");
//     ok = ft_lstnew("ok");
//     dude = ft_lstnew("haha");

//     head->next = ok;
//     ok->next = dude;

//     ft_lstclear(&head,delet);
// }