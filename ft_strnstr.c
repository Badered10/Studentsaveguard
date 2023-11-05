/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:28:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/05 11:28:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    char *ocean;
    char *fish;

    ocean = (char *)haystack;
    fish =  (char *)needle;
    if (!needle)
        return(ocean);
    while(len-- > 0 && *ocean)
    {
        while((*fish && *ocean) && (*ocean == *fish))
            ocean++, fish++;
        if (!*fish)
            return (ocean -= ft_strlen(needle), ocean) ;
        fish = (char*)needle;
        ocean ++;
    }
    return (NULL);
}
// int main()
// {
//     char *source= "";
//     char *to_find= "lo";
//     char *res = ft_strnstr(source,to_find,1);
//     printf("\nresult is :%s",res);
// }