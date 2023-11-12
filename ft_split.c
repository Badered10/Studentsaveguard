/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:18:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/12 09:29:57 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	**ft_strdupp(char **res)
{
    res = (char**)malloc(sizeof(char*) *  1);
    if(!res)
    return NULL;
    *res = ft_strdup("");
	return (res);
}

static int ft_wcounter(const char *s, char c)
{
    char *x;
    int words;

    words = 0;
    x = (char*)s;
    while(*x)
    {
        while(*x == c)
        x++;
        if(*x != c && *x)
        {
            while(*x != c && *x)
            x++;
            words++;            
        }
    }
    return (words);
}

char **ft_split(char const *s, char c)
{
    char **res = NULL;
    char *p;
    char *start;
    int words;
    int to_free;
    
    to_free = 1;
    words = ft_wcounter(s, c);
    if(!words)
    return (ft_strdupp(res));
    res = (char**)malloc(sizeof(char*) * (words + 1));
    if(!res)
    return NULL;
    p = (char*)s;
    while(words--)
    {
        while(*p == c)
        p++;
        start = p;
        while(*p != c && *p)
            p++;   
        *res = ft_substr(start,0,p - start);
        if(!*res)
        {
            to_free = 1;
            to_free = ft_wcounter(s, c) - words; 
            while(to_free-- >= 0)
            free(res[to_free]);
            free(res);
            return NULL;
        }
        res++;
    }
    *res = NULL;
    words = ft_wcounter(s, c);
    return(res - words);
}
int main ()
{
    const char *s =" cx  asd dsa";
    char c = ' ';
    char **k = ft_split(s, c);
    int i = 0;
    int words;
    words = ft_wcounter(s, c);
    if(words == 0)
    words = 1;
     while(i < words)
     {
        printf("%s\n",k[i]);
        i++;
     }
}