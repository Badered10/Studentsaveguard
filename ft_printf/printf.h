/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/11 21:25:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
    size_t	len;
    size_t	width;
    int	    spaces;
    int	    zeros;
    int     count;
    int		mince;
	int		zero;
	int		point;
    int     d;
}               f;
int ft_printf(char *string , ...);
int specifier(char c,va_list args);
int ft_putchar(char c);
int is_specifier(char c);

#endif