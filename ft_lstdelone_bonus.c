/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:29:19 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/16 18:18:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
    return;
    del(lst->content);
    free(lst); 
}
// void delet(void *content)
// {
//     free(content);
//     content = NULL;
// }
// int main()
// {
//     t_list *first;
//     t_list *oke;
//     t_list *last;

//     char *k = "hello";
//     char *i = "ok";
//     char *j = "last";

    
//     first = ft_lstnew(k);
//     oke = ft_lstnew(i);
//     last = ft_lstnew(j);

//     last->content = malloc(ft_strlen(j) + 1);
//     ft_strlcpy(last->content,j,ft_strlen(j) + 1);

//     first->content = oke;
//     oke->content = last;

//     printf("%s\n",last->content);
//     ft_lstdelone(last,delet);
// }