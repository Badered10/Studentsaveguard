/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:18:29 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/11 22:19:17 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	**ft_strdupp(const char *s1)
{
	char	*copy;
	size_t	lenth;
    char    **res;

    res = (char**)malloc(sizeof(char*) * (words + 1));
    if(!res)
    return NULL;
	lenth = ft_strlen(s1);
	copy = (char *)malloc(lenth + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, lenth + 1);
	return (copy);
}

static int ft_wcounter(const char *s, char c)
{
    char *x;
    int i;

    i = 0;
    x = (char*)s;
    while(*x)
    {
        while(*x == c)
        x++;
        if(*x != c && *x)
        {
            while(*x != c && *x)
            x++;
            i++;            
        }
        while(*x == c)
        x++;
    }
    return (i);
}

char **ft_split(char const *s, char c)
{
    char **res = NULL;
    char *p;
    char *start;
    int words;
    
    words = ft_wcounter(s, c);
    if(!words)
    return (*res = strdup(""), res);
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
            while(words--)
            free(res[words]);
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
    const char *s ="         ";
    char c = ' ';
    // char **k = ft_split(s, c);
    // int i = 0;
    printf("%d",ft_wcounter(s, c));
    //  while(i < ft_wcounter(s, c))
    //  {
    //     printf("%s\n",k[i]);
    //     i++;
    //  }
}