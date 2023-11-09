/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:07:15 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/09 22:28:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *new;
    
    new = (char*)ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
    if (!new)
    return(NULL);
    ft_memcpy(new,s1,ft_strlen(s1));
    ft_memcpy(new + ft_strlen(s1),s2,ft_strlen(s2));
    return(new);
}
/*
int main()
{
    char s1[]="hello";
    char s2[]=" world";
    char *s3;
    s3 = ft_strjoin(s1,s2);
    printf("%s\t lenth=%zu",s3,ft_strlen(s3));
    free(s3);
}
*/