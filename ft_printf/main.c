/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/10 18:44:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <string.h>
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
    char *c = "423lasasdasdasdd";
   printf("'%zu'\n",ft_strlen(ft_itoa(ft_atoi(c))));
//     char* k = "3333";
//    printf("'%5.s'\n",k);
    // int c = 999999;
    // printf("'%09.1d'\n",c);
}