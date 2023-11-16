/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:09:05 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/16 16:16:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
    return (NULL);
    new->content = content;
    new->next = NULL;
    return(new);
}

// int main()
// {
//     t_list *new;

//     int arr[] = {1,23,2};

//     new = ft_lstnew(arr);
    
//     new->content = (int *)new->content + 0;
    
//     printf("%d",*((int*)new->content));
// }