/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:13:54 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 15:39:22 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ze_print(f *nes, unsigned int x)
{
	if (nes->zero == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_putunbr_fd(x, 1);
	}
	else
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		nes->count += ft_putunbr_fd(x, 1);
	}
}

static void	m_print(f *nes, unsigned int x)
{
	if (nes->mince == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		if (nes->point == 1)
		{
			if (!x && nes->tmp <= 0)
				;
			else
				nes->count += ft_putunbr_fd(x, 1);
		}
		else
			nes->count += ft_putunbr_fd(x, 1);
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
	}
}
static void	p_print(f *nes, unsigned int x)
{
	if (nes->point == 1)
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		if (x)
			nes->count += ft_putunbr_fd(x, 1);
		else if (nes->tmp > 0)
			nes->count += ft_putunbr_fd(x, 1);
	}
}

static void	ft_check_x_point(char *string, f *nes, unsigned int x)
{
	if (*string == '.')
	{
		nes->point = 1;
		if (*string)
			string++;
		if (ft_isdigit(*string))
		{
			nes->zeros = ft_atoi(string);
			nes->tmp = nes->zeros;
			if (nes->zeros > nes->len)
				nes->zeros -= nes->len;
			else
				nes->zeros = 0;
		}
		if (!x && nes->stmp >= 1 && nes->tmp <= 0)
			nes->spaces++;
	}
	else if (nes->zero == 1)
		nes->zeros = nes->spaces;
		if (((nes->zeros > 0) || (nes->len == nes->tmp)) && (nes->d < 0
			&& nes->point == 1))
				nes->zeros++;
	nes->spaces -= nes->zeros;
}

static void	ft_skip(char **string, f *nes)
{
	while (*(*string) == '0' && *(*string))
	{
		nes->zero = 1;
		(*string)++;
	}
	while (*(*string) == '-' && *(*string))
	{
		nes->zero = 0;
		nes->mince = 1;
		(*string)++;
	}
}
int	ft_uflags(char *string, unsigned int x)
{
	f		nes;
	char	*str;

	// printf("taqtaq\n");
	nes.zeros = 0;
	nes.zero = 0;
	nes.spaces = 0;
	nes.point = 0;
	nes.mince = 0;
	nes.count = 0;
	nes.tmp = -999999999;
	nes.stmp = -999999999;
	str = ft_uitoa(x);
	nes.len = ft_strlen(str);
	free(str);
	ft_skip(&string, &nes);
	ft_checkspaces(&string, &nes);
	ft_check_x_point(string, &nes, x);
	if (nes.mince == 1 )
		m_print(&nes, x);
		else if (nes.point == 1)
			p_print(&nes,x);
			else
				ze_print(&nes, x);
	return (nes.count);
}
