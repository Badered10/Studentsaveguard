/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:31:02 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 22:19:08 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>
#include <limits.h>
int main()
{
	// char *str = NULL;

	// printf("--------- # flag -----------------|%10.20d|

	int x;
	int y;


	// x = ft_printf("me|% -10d|\n",391876567);
	// y = printf("or|% -10d|\n",391876567);
	// printf("%d , %d \n",x,y);
	// ft_printf("me|%-10.20d|\n",-391876567);
	// printf("or|%-10.20d|\n",-391876567);
	// ft_printf("me|%-10.20d|\n",0);
	// printf("or|%-10.20d|\n",0);

	// printf("-----------------------------\n\n");

	// ft_printf("me|%-10.20d|\n",391876567);
	// printf("or|%-10.20d|\n",391876567);
	// ft_printf("me|%-10.20d|\n",-391876567);
	// printf("or|%-10.20d|\n",-391876567);
	// ft_printf("me|%-10.20d|\n",0);
	// printf("or|%-10.20d|\n",0);

	// printf("------------   #   -----------------\n\n");


	// x = ft_printf("me|%#32.32X|\n",1927970300);
	// y = printf("or|%#32.32X|\n",1927970300);
	// printf("%d , %d \n",x,y);
	// x = ft_printf("me|%#16x|\n",-391876567);
	// y = printf("or|%#16x|\n",-391876567);
	// printf("%d , %d \n",x,y);
	// x = ft_printf("me|%16x|\n",0);
	// y = printf("or|%16x|\n",0);
	// printf("%d , %d \n",x,y);
	
	// printf("------------- #  and  - flags ----------------\n\n");


	// x = ft_printf("me|%#-15x|\n",391876567);
	// y = printf("or|%#-15x|\n",391876567);  
	// printf("%d , %d \n",x,y); 
	// x = ft_printf("me|%#-15x|\n",-391876567);
	// y = printf("or|%#-15x|\n",-391876567);
	// printf("%d , %d \n",x,y);
	// x = ft_printf("me|%#-15x|\n",0);
	// y = printf("or|%#-15x|\n",0);
	// printf("%d , %d \n",x,y);



	// printf("------------- #  and  0 flags ----------------\n\n");

	// x = ft_printf("me|%#015x|\n",391876567);
	// y = printf("or|%#015x|\n",391876567);
	// printf("%d , %d \n",x,y);
	// x = ft_printf("me|%#015x|\n",-391876567);
	// y = printf("or|%#015x|\n",-391876567);
	// printf("%d , %d \n",x,y);
	// x = ft_printf("me|%#015x|\n",0);
	// y = printf("or|%#015x|\n",0);
	// printf("%d , %d \n",x,y);


	// ft_printf("me|%#.29d|\n",-391876567);
	// printf("or|%#.29d|\n",-391876567);
	// ft_printf("me|%#.29d|\n",-391876567);
	// printf("or|%#.29d|\n",-391876567);
	// ft_printf("me|%#.29d|\n",0);
	// printf("or|%#.29d|\n",0);

	// ft_printf("me|%#.29d|\n",-391876567);
	// printf("or|%#.29d|\n",-391876567);
	// ft_printf("me|%#.29d|\n",-391876567);
	// printf("or|%#.29d|\n",-391876567);
	// ft_printf("me|%#.29d|\n",0);
	// printf("or|%#.29d|\n",0);
	// ft_printf("or|%020d|\n",-43); 
	// 20 - 3 = 17 , 10 - 3 = 7, 17 - 7 = sp  = 9, zr = 8
	// if (nes.d < 0)
	//	nes.zeros#;
	//	nes.spaces--;




	// 42%56.2d42
	// ft_printf("me42%56.2d42\n",-391876567);
	// printf("or42%56.2d42\n",-391876567);
	// system("leaks a.out");
	
	y = ft_printf("me|%3.12x|",1);
	printf("\n");
	x = printf("or|%3.12x|",1);
	printf("\n");
	printf("me % - ----  d them % - ----  d\n",x,y);
	// y = ft_printf("me|%000+10.20d\n",-391876567);
	// x = printf("or|%000+10.20d\n",-391876567);
	// printf("me % - ----  d them % - ----  d\n",x,y);
	// y = ft_printf("me|%0+000000+10.20d|\n",2);
	// x = printf("me|%0+000000+10.20d|\n",2);
	// printf("me % - ----  d them % - ----  d\n",y,x);
	// y = ft_printf("me|%00  00  00032.20d| |%00 00 00 32.20d| |%0 000 00032.20d|\n",-2,2,0);
	// x = printf("me|%00  00  00  032.20d| |%0000  00 032.20d| |% 000 000032.20d|\n",-2,2,0);
	// printf("me % - ----  d them % - ----  d\n",y,x);
	// y = ft_printf("me|%+-32.20d| |%+-32.20d| |%+-32.20d|\n",-2,2,0);
	// x = printf("me|%+-32.20d| |%+-32.20d| |%+-32.20d|\n",-2,2,0);
	// printf("me % - ----  d them % - ----  d\n",y,x);
	// y = ft_printf("me|%-32.20d|\n",-2);
	// x = printf("me|%-32.20d|\n",-2);
	// printf("me %d them %d\n",y,x);
}
