/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/14 11:09:38 by baouragh         ###   ########.fr       */
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
    // main vars
    unsigned long   num; 
    int             d;
    unsigned int    ud;
    /// to_print vars
    int             count;
    int	            spaces;
    int	            zeros;
    int             display;
    int	            len;
    // flags
    int		        mince;
	int		        zero;
	int		        point;
    int             hashtag;
}               f;
int     ft_printf(char *string , ...);
int     specifier(char c,va_list args);
int     ft_dflags(char *string, int x);
int     ft_isflag(char ch , char *save_m ,va_list args);
int     ft_cflags(char *save_m ,int x);
int     ft_uflags(char *string, unsigned int x);
int     ft_sflags(char *string, char *res);
int     ft_pflags(char *string, void* res, char c);
int     ft_xsflags(char *string, unsigned int x , char c);

#endif