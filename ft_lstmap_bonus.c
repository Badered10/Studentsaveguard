/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:33 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 20:32:40 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    if (!lst || !f || !del)
    return (NULL);
    void *new_content;
    t_list *new_list;
    t_list *new_node;
    (lst)
    {
        new_content = f(lst->content);
        if (!new_content)
        {
            ft_lst_clear(&new_list ,new_content);
            return(NULL);
        }
        new_node = ft_lstnew(new_content);
        if (!new_node)
        {
            del(new_content);
            ft_lstclear(&new_list,new_node);
            return (NULL);
        }
        t_lstadd_back(&new_list,new_node);
        lst = lst->next;
    }
    return(new_list);
}