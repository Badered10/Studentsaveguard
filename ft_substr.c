/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:12:11 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/12 11:43:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s|--------start------------len---->/0

//     1) if len > l_sub; --> len = l_sub;  || ----> return (substring);

//     2) if start > l_sub or len = 0 ---> return (empty substring);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l_total;
	size_t	l_sub;

	l_total = ft_strlen(s);
	l_sub = l_total - start;
	if (!s)
		return (NULL);
	if (start > l_total || !len)
		return (ft_strdup(""));
	if (len > l_sub)
		len = l_sub;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, (len + 1));
	return (res);
}
// int main()
// {
//     char str[12] = "hello world";
//     char *key;
//     key = ft_substr(str,11,1);
//     printf("%s",key);
// }
