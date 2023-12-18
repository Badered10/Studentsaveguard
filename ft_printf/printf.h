/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 15:14:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	// main vars
	unsigned long	num;
	int				d;
	unsigned int	ud;
	/// to_print vars
	int				count;
	int				spaces;
	int				zeros;
	int				display;
	int				len;
	int				tmp;
	int				stmp;
	// flags
	int				plus;
	int				space;
	int				mince;
	int				zero;
	int				point;
	int				hashtag;
} f;

int					ft_printf(char *string, ...);
int					ft_dflags(char *string, int x);
int					ft_isflag(char ch, char *save_m, va_list args);
int					ft_cflags(char *save_m, int x);
int					ft_uflags(char *string, unsigned int x);
int					ft_sflags(char *string, char *res);
int					ft_pflags(char *string, void *res, char c);
int					ft_xsflags(char *string, unsigned int x, char c);
void				ft_d_initialize(f *nes, int x);
void				ft_d_search(f *nes, char **string);
void				ft_checkspaces(char **string, f *nes);
void				ft_checkpoint(char *string, f *nes, unsigned int x);
void				ft_dcheckpoint(char **string, f *nes, int x);
#endif