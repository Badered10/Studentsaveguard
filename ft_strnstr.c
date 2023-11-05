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
    size_t fish_len;

    ocean = (char *)haystack;
    fish = (char *)needle;
    fish_len = ft_strlen(needle);

    if(!fish_len)
    return(ocean);

    while(len-- > 0 && *ocean)
    {
         while(*ocean++ == *fish++ && *fish)
            printf("%c\t%c\n",*ocean,*fish);
        
        
        if (!*fish)
            return(ocean - fish_len);
            printf("%c\t%c\n",*ocean,*fish);
        ocean ++;
    }
    return(NULL);
}
int main()
{
    char *source= "hello world i am bader";
    char *to_find= "am";
    char *res = ft_strnstr(source,to_find,16);
    printf("result is : %s",res);
}