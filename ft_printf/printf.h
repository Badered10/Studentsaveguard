/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/12 18:29:41 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include "/Users/baouragh/Desktop/ALL/ft_printf/libft/libft.h" 

typedef struct s_flags
{
    size_t	width;
    int	    len;
    int	    spaces;
    int	    zeros;
    int     count;
    int		mince;
	int		zero;
	int		point;
    int     d;
}               f;
int     ft_printf(char *string , ...);
int     specifier(char c,va_list args);
int     ft_dflags(char *string, int x);
int     ft_isflag(char ch , char *save_m ,va_list args);

#endif