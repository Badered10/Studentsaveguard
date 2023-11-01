/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/01 11:05:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include<unistd.h>
# include<string.h>
# include<stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);

#endif
