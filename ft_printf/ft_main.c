/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/15 11:25:57 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>
int main()
{
	// int d = 6;
	
	int y = ft_printf("me|%5.d|\n",10); 
	int x = printf("or|%5.d|\n",10);
	printf("me %d them %d\n",x,y);
	y = ft_printf("me|%5.d|\n",-10); 
	x = printf("or|%5.d|\n",-10);
	printf("me %d them %d\n",x,y);
	y = ft_printf("me|%5.d|\n",0); 
	x = printf("or|%5.d|\n",0);
	printf("me %d them %d\n",x,y);
	
	// x = ft_printf("me|%-30d|\n",20);
	// y = printf("or|%-30d|\n",20);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%-30d|\n",-20);
	// y = printf("or|%-30d|\n",-20);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%-30d|\n",0);
	// y = printf("or|%-30d|\n",0);
	// printf("me %d them %d\n",x,y);
	
	// x = ft_printf("me|%0+30.20d|\n",30);
	// y = printf("or|%0+30.20d|\n",30);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|% 030d|\n",-30);
	// y = printf("or|% 030d|\n",-30);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|% 030d|\n",0);
	// y = printf("or|% 030d|\n",0);
	// printf("me %d them %d\n",x,y);
	
	// x = ft_printf("me|%30d|\n",40);
	// y = printf("or|%30d|\n",40);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%30d|\n",-40);
	// y = printf("or|%30d|\n",-40);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%30d|\n",0);
	// y = printf("or|%30d|\n",0);
	// printf("me %d them %d\n",x,y);

	// x = ft_printf("me|%0+30.20d|\n",50);
	// y = printf("or|%0+30.20d|\n",50);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%0+30.20d|\n",-50);
	// y = printf("or|%0+30.20d|\n",-50);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%0+30.20d|\n",0);
	// y = printf("or|%0+30.20d|\n",0);
	// printf("me %d them %d\n",x,y);

	// x = ft_printf("me|%20d|\n",0); // --->> 
	// y = printf("or|%20d|\n",0);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%20d|\n",-60);
	// y = printf("or|%20d|\n",-60);
	// printf("me %d them %d\n",x,y);
	// x = ft_printf("me|%20d|\n",0);
	// y = printf("or|%20d|\n",0);
	// printf("me %d them %d\n",x,y);
}
