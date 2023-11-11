/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:28:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/11 13:14:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ocean;
	char	*fish;
	int		i;

	i = 0;
	ocean = (char *)haystack;
	fish = (char *)needle;
	if (!*needle)
		return (ocean);
	while (len && *ocean)
	{
		while ((*fish && *ocean) && (*ocean == *fish) && len)
		{
			ocean++;
			fish++;
			i++;
			len--;
		}
		len += i;
		ocean -= i;
		i = 0;
		len--;
		if(!len && *fish)
		return (NULL);
		if (!*fish)
			return (ocean);
		ocean++;
		fish = (char *)needle;
	}
	return (NULL);
}

// int	main(void)
// {
// char *haystack = "MZIRIBMZIRIBMZE123";
// 	char *needle = "MZIRIBMZE";
// 	char * empty = (char*)"";
// 	empty = ft_strnstr(haystack,needle,ft_strlen(needle));
// 	printf("%s",empty);
// }
