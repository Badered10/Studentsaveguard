/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/10 18:23:47 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
// int main()
// {
// 	char *string = "123232dasdasd";
//     string +=3;
// 	int x = atoi(string);
// 	printf("%d",x);
// }
int main()
{
    unsigned int c = 423;
   printf("'%+u'\n",c);
//     char* k = "3333";
//    printf("'%5.s'\n",k);
    // int c = 999999;
    // printf("'%09.1d'\n",c);
}