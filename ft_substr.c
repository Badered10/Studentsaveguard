/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:12:11 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/06 22:12:13 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *to_start;
    char *to_last;
    size_t total;
    size_t rest;
    size_t removed;

    to_start = (char*)s;
    while(start-- > 0)
    to_start++;
    total = ft_strlen(to_start);
    to_last = to_start + len;
    rest = ft_strlen(to_last);
    removed = total - rest;
    ft_bzero(to_last,removed);
    return(ft_strdup(to_start));
}
int main()
{
  char *str = "Hello World";
   char *copy = ft_substr(str,6,5);
   printf("copy:%s",copy);
}