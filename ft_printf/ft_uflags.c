/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uflags_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:13:54 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/17 18:19:13 by baouragh         ###   ########.fr       */
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

static void	mp_print(f *nes, unsigned int x)
{
	if (nes->mince == 1)
	{
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_putunbr_fd(x, 1);
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
	}
	else if (nes->point == 1)
	{
		while ((nes->spaces)-- > 0)
			nes->count += write(1, " ", 1);
		while ((nes->zeros)-- > 0)
			nes->count += write(1, "0", 1);
		nes->count += ft_putunbr_fd(x, 1);
	}
}

static void	ft_checkpoint(char *string, f *nes)
{
	if (*string == '.')
	{
		nes->point = 1;
		string++;
		if (ft_isdigit(*string))
		{
			nes->zeros = ft_atoi(string);
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

static void	ft_checkspaces(char **string, f *nes)
{
	if (ft_isdigit(*(*string)))
	{
		nes->spaces = ft_atoi(*string);
		if (nes->spaces > nes->len)
			nes->spaces -= nes->len;
		else
			nes->spaces = 0;
	}
	else
		nes->spaces = 0;
	while (ft_isdigit(*(*string)))
		(*string)++;
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
	str = ft_uitoa(x);
	nes.len = ft_strlen(str);
	free(str);
	ft_skip(&string, &nes);
	ft_checkspaces(&string, &nes);
	ft_checkpoint(string, &nes);
	if (nes.mince == 1 || nes.point == 1)
		mp_print(&nes, x);
	else
		ze_print(&nes, x);
	return (nes.count);
}
