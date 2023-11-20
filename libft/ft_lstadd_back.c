/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:55 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/16 12:10:20 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst || !new)
    return ;
    *lst = ft_lstlast(*lst);
    *lst->next = new;
    new->next = NULL;
}
int main()
{
    t_list *first;
    t_list *second;
    t_list *third;
    t_list *last;

    first  = ft_lstnew("one");
    second = t_lstnew("two");
    third  = ft_lstnew("three");
    last   = ft_lstnew("and four");
    
}