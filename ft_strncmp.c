/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:11:27 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/01 11:11:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<string.h>

int ft_strncmp(const char *s1, const char *s2 , size_t n)
{
    int i;

    i = 0;
    while(n - 1 > 0 && s1[i] - s2[i] == 0)
    {
        i++;
        n--;
    }
    return(s1[i] - s2[i]);
}
int main()
{
    char *d1 = "hells";
    char *d2 = "helll";
    printf("%d\n org : %d", ft_strncmp(d1, d2, 5), strncmp(d1, d2, 5));
}