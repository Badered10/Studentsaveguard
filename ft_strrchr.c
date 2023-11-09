/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:43:52 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/09 22:59:12 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (s[len] != (char)c && len >= 0)
		len--;
	if (len < 0)
		return (NULL);
	return ((char *)(s + len));
}
int main()
{
	char *str;
	str = ft_strrchr("testeaA",1121);
	printf("%s",str);
}