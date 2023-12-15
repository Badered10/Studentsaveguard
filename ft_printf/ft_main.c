/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/15 09:30:02 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>
int main()
{
	// int d = 6;
	
	// int x = ft_printf(str,"hello");
	int y = ft_printf("me|%-10.1000s|\n","hello, world!!");  //sp = 40; zeros = 0; len = 10; sp = 0  zr = 30 ->> sp >> zr >> nb , zr >> nbr >> sp
	int x = printf("me|%-10.1000s|\n","hello, world!!");
	printf("me %d them %d\n",y,x);
	
	// x = ft_printf("me|%-30d|\n",20);
	// y = printf("or|%-30d|\n",20);
	// printf("me %d them %d\n",y,x);
	// x = ft_printf("me|%-30d|\n",-20);
	// y = printf("or|%-30d|\n",-20);
	// printf("me %d them %d\n",y,x);
	
	// x = ft_printf("me|% 030d|\n",30);
	// y = printf("or|% 030d|\n",30);
	// printf("me %d them %d\n",y,x);
	// x = ft_printf("me|% 030d|\n",-30);
	// y = printf("or|% 030d|\n",-30);
	// printf("me %d them %d\n",y,x);
	
	// x = ft_printf("me|%30d|\n",40);
	// y = printf("or|%30d|\n",40);
	// printf("me %d them %d\n",y,x);
	// x = ft_printf("me|%30d|\n",-40);
	// y = printf("or|%30d|\n",-40);
	// printf("me %d them %d\n",y,x);

	// x = ft_printf("me|%0+30.20d|\n",50);
	// y = printf("or|%0+30.20d|\n",50);
	// printf("me %d them %d\n",y,x);
	// x = ft_printf("me|%0+30.20d|\n",-50);
	// y = printf("or|%0+30.20d|\n",-50);
	// printf("me %d them %d\n",y,x);
}
