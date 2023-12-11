/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/11 21:45:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>
// int main()
// {
// 	char *string = "123232dasdasd";
//     string +=3;
// 	int x = atoi(string);
// 	printf("%d",x);
// }
int main()
{
    char c = 'k';
//    printf("'%zu'\n",ft_strlen(ft_itoa(ft_atoi(c))));
//     char* k = "3333";
//    printf("'%5.s'\n",k);
    printf("'%15.6p'\n",&c);
}