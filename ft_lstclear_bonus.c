/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:19:09 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/16 18:20:09 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void delet(void *lst)
{
    free(lst);
}
void del(void *content)
{
    free(content);
    content = NULL;
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *tmp;
 
    tmp = NULL;
    if (!lst  || !del)
    return ;
    while (*lst)
    {
       tmp = (*lst)->next;
       ft_lstdelone(*lst,del);
       del((void*)*lst);
       *lst = tmp;          
    }
}
int main()
{
    t_list *head;
    t_list *ok;
    t_list *dude;

    char *ok1 = "hello";
    char *ok2 = "hello2";
    char *ok3 = "hello3";
    
    head = ft_lstnew(ok1);
    ok = ft_lstnew(ok2);
    dude = ft_lstnew(ok3);

    head->next = ok;
    ok->next = dude;

    ft_lstclear(&head,delet);
}