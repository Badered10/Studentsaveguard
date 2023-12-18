/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsflags_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:51 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/18 15:19:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ze_print(f *nes, unsigned int x, char c)
{
	if (nes->zero == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_puthexa_fd(x, 1, c);
	}
	else
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		if (nes->hashtag == 1 && x && c == 'x')
			nes->count += write(1, "0x", 2);
		else if (nes->hashtag == 1 && x && c != 'x')
			nes->count += write(1, "0X", 2);
		nes->count += ft_puthexa_fd(x, 1, c);
	}
}

static void	mp_print(f *nes, unsigned int x, char c)
{
	if (nes->mince == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_puthexa_fd(x, 1, c);
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
	}
	else if (nes->point == 1)
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		if (nes->hashtag == 1 && x && c == 'x')
			nes->count += write(1, "0x", 2);
		else if (nes->hashtag == 1 && x && c != 'x')
			nes->count += write(1, "0X", 2);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_puthexa_fd(x, 1, c);
	}
}

static void	check_hashtag(f *nes, unsigned int x, char c)
{
	if (nes->hashtag == 1 && x)
	{
		if (((nes->mince == 1 && x) || (nes->zero && !nes->point)) && c == 'x')
			nes->count += write(1, "0x", 2);
		else if (((nes->mince == 1 && x) || (nes->zero && !nes->point))
			&& c != 'x')
			nes->count += write(1, "0X", 2);
		if ((nes->zero == 1 && nes->tmp <= nes->len) || nes->tmp == -999999999)
			nes->zeros -= 2;
		if (nes->tmp != -999999999 || nes->point == 0)
			nes->spaces -= 2;
	}
}

static void	check_x_point(char *string, f *nes)
{
	if (*string == '.' && *(string + 1))
	{
		nes->point = 1;
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
	}
	else if (nes->zero == 1)
		nes->zeros = nes->spaces;
	nes->spaces -= nes->zeros;
}

static void	ft_search(char **string, f *nes)
{
	while (ft_isdigit_nz(*(*string)) != 1 && *(*string) != '.'
		&& *(*string) != 'x' && *(*string) != 'X' && *(*(string)))
	{
		if (*(*string) == '#')
			nes->hashtag = 1;
		else if (*(*string) == '0')
		{
			if (nes->mince == 0)
				nes->zero = 1;
		}
		else if (*(*string) == '-')
		{
			nes->zero = 0;
			nes->mince = 1;
		}
		(*string)++;
	}
}

static int	hexalenth(unsigned long n)
{
	int	res;

	res = 1;
	if (n > 0)
		res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
	return (res);
}
int	ft_xsflags(char *string, unsigned int x, char c)
{
	f	nes;

	nes.mince = 0;
	nes.zero = 0;
	nes.hashtag = 0;
	nes.point = 0;
	nes.zeros = 0;
	nes.count = 0;
	nes.len = 0;
	nes.tmp = -999999999;
	nes.len += hexalenth(x);
	ft_search(&string, &nes);
	ft_checkspaces(&string, &nes);
	check_x_point(string, &nes);
	check_hashtag(&nes, x, c);
	if (nes.mince == 1 || nes.point == 1)
		mp_print(&nes, x, c);
	else
		ze_print(&nes, x, c);
	return (nes.count);
}
