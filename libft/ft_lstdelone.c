/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:29:19 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/16 14:37:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void delet(void *content)
{
    free(content);
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
    return;
    del(lst->content);
    free(lst); 
}

int main()
{
    t_list *head;
    t_list *node;
    t_list *tail;
    head = ft_lstnew("hello");
    node = ft_lstnew("okey");
    tail = ft_lstnew("last");

    head->next = node;
    node->next = tail;
    
    while(head)
    {
        printf("%s\n",(char*)head->content);
        head = head->next;
    }
    ft_lstdelone(tail,delet);
    printf("%p",tail);
}
