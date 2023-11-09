/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:07:53 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/08 18:18:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	lenth;

	lenth = ft_strlen(s1);
	copy = (char *)malloc(lenth + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, lenth + 1);
	return (copy);
}
/*
int	main(void)
{
	char	*copy;

	const char *str= "hello wolrd my name is bader";
	copy = NULL;
	copy = ft_strdup(str);
	printf("copy:%s\t str:%s\n",copy,str);
	printf("lenth of copy is :%zu \t
		lenth of str:%zu",ft_strlen(copy),ft_strlen(str));
	free(copy);
}
*/
