/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:09:27 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/01 10:05:49 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include"libft.h"
# include <stdio.h>

size_t	ft_strlen(char  *s)
{
	char *tmp = s;
	while (*s++);
	s -= 1;
	return (s - tmp);
}

int main() {
	fprintf( stderr, "chh %zu\n", strlen(NULL));
}