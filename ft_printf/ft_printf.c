/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 22:44:25 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_scanstring(char *ptr, char *save_m, f *t, va_list args)
{
	while (*ptr)
	{
		if (*ptr == '%')
		{
			save_m = ptr;
			if (*ptr)
				ptr++;
			while (*ptr)
			{
				if (ft_strchr("cspdiuxX%", *ptr))
				{
					t->count += ft_isflag(*(ft_strchr("cspdiuxX%", *ptr)),
							save_m, args);
					break ;
				}
                if(ft_strchr("-0. #+",*ptr) == NULL && ft_isdigit(*ptr) == 0)
                {
                    // printf("oh hell no !\n");
                    t->count += write(1,ptr,1);
                    break;
                }
				else if (!*ptr)
					break ;
				ptr++;
			}
		}
		else
			t->count += write(1, ptr, 1);
		if (!*ptr)
			break ;
		ptr++;
	}
}

int	ft_printf(char *string, ...)
{
	va_list	args;
	f		t;
	char	*ptr;
	char	*save_m;

	save_m = NULL;
	ptr = string;
	t.count = 0;
	va_start(args, string);
	ft_scanstring(ptr, save_m, &t, args);
	va_end(args);
	return (t.count);
}
