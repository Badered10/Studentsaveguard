/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/15 17:43:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <string.h>
int main()
{
	// int d = 6;
	
	int y = ft_printf("me|%+000+++5.10d|\n",10); 
	int x = printf("or|%+000+++5.10d|\n",10);
	printf("me %d them %d\n",x,y);
	y = ft_printf("me|%+000+++5.10d|\n",-10); 
	x = printf("or|%+000+++5.10d|\n",-10);
	printf("me %d them %d\n",x,y);
	y = ft_printf("me|%+000+++5.10d|\n",0);
	x = printf("or|%  0 5.10d|\n",0);
	printf("me %d them %d\n",x,y);
}
