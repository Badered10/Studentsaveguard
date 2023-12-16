/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 10220/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 20220/12/15 22:36:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>
#include <limits.h>
int main()
{
	// char *str = NULL;
	ft_printf("42% 54d42\n",10);
	printf("42% 54d42\n",10);
	// system("leaks a.out");
	
	// int y = ft_printf("me|%+000+++10.20d\n",10);
	// int x = printf("or|%+000+++10.20d\n",10);
	// printf("me % - ----  d them % - ----  d\n",x,y);
	// y = ft_printf("me|%+000+++10.20d\n",-10);
	// x = printf("or|%+000+++10.20d\n",-10);
	// printf("me % - ----  d them % - ----  d\n",x,y);
	// y = ft_printf("me|%0+++000000+++++++10.20d|\n",2);
	// x = printf("me|%0+++000000+++++++10.20d|\n",2);
	// printf("me % - ----  d them % - ----  d\n",y,x);
	// y = ft_printf("me|%000000010.20d| |%000000010.20d| |%000000010.20d|\n",-2,2,0);
	// x = printf("me|%000000010.20d| |%000000010.20d| |%000000010.20d|\n",-2,2,0);
	// printf("me % - ----  d them % - ----  d\n",y,x);
	// y = ft_printf("me|%++++++++++10.20d| |%++++++++++10.20d| |%++++++++++10.20d|\n",-2,2,0);
	// x = printf("me|%++++++++++10.20d| |%++++++++++10.20d| |%++++++++++10.20d|\n",-2,2,0);
	// printf("me % - ----  d them % - ----  d\n",y,x);
	// y = ft_printf("me|%10.20d|\n",-2);
	// x = printf("me|%10.20d|\n",-2);
	// printf("me %d them %d\n",y,x);
}
