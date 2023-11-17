/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:33 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/17 19:58:28 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    if (!lst || !f || !del)
    return (NULL);

    t_list *tmp;
    while(lst)
    {
        tmp = f(lst);
        if (!tmp)
        {
            del(tmp->content)
            ft_lstclear(tmp);
        }
        ft_lstadd_back(tmp);
        lst = lst->next;
    }
}