/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:31:02 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 21:02:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	// int	x;
	// int	y;
	// int	x;
	// int	y;
	// char *str = NULL;
	// printf("--------- # flag -----------------|%10.20d|
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
	// ft_printf("%-3i", 0)
	// ft_printf("%8.5i", 0)
	// ft_printf("%-8.5i", 0)
	// ft_printf("%08.5i", 0)
	// ft_printf("%-3d", 0)
	// x = ft_printf("%0168.128u%0054.92x%30.171s", 2620195206u,
	// printf("\n"); // if( !nes.tmp == 0 || !nes.tmp == -9999999999 && x == 0 )
	// ->> not print
	// y = printf("%0168.128u%0054.92x%30.171s", 2620195206u, 1771128939u
	// printf("\n");
	// printf("-----my %d-------there %d--------\n", x, y);
	// x = ft_printf("|%.u|\n", 0);
	// y = printf("|%.u|\n", 0);
	// printf("-----my %d-------there %d--------\n",x,y);
	// x = ft_printf("|%5.0u|\n", 0);
	// y = printf("|%5.0u|\n", 0);
	// printf("-----my %d-------there %d--------\n",x,y);
	// x = ft_printf("|%5.u|\n", 0);
	// y = printf("|%5.u|\n", 0);
	// printf("-----my %d-------there %d--------\n",x,y);
	// x = ft_printf("|%-5.0u|\n", 0);
	// y = printf("|%-5.0u|\n", 0);
	// printf("-----my %d-------there %d--------\n",x,y);
	// x = ft_printf("|%-3.2s|\n", NULL);
	// y = printf("|%-3.2s|\n", NULL);
	// printf("-----my %d-------there %d--------\n",x,y);
	// ft_printf("|%-3d|\n", 0);
	// printf("|%-3d|\n", 0);
	// y = ft_printf("me|%000+10.20d\n",-391876567)
	// --------+---->+
	// va_arg(list, type)    (*(type *)((list += sizeof(type)
	ft_printf("%+3s", NULL);
	printf("\n\n");
	printf("%3s", NULL);
	// int x = 4;
	//  ft_printf("%d", x);
	// va_list list;
	// va_sta
	// char *s = "ismailaaddda";
	// void *d;
	// char *str = s;
	// int x = sizeof(d);
	// str += sizeof(s) - sizeof(s);
	// printf("%d , %d", *str,x);
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
