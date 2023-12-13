/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 15:54:33 by baouragh         ###   ########.fr       */
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
    int	            len;
    int	            spaces;
    int	            zeros;
    int             count;
    int             display;
    int		        mince;
	int		        zero;
	int		        point;
    unsigned long   num; 
    int             d;
}               f;
int     ft_printf(char *string , ...);
int     specifier(char c,va_list args);
int     ft_dflags(char *string, int x);
int     ft_isflag(char ch , char *save_m ,va_list args);
int     ft_cflags(char *save_m ,int x);
int     ft_uflags(char *string, unsigned int x);
int     ft_sflags(char *string, char *res);
int     ft_pflags(char *string, char *res);

#endif