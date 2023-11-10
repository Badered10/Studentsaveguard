/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:28:45 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/10 14:27:27 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ocean;
	char	*fish;
	int	i;

	i = 0;
	ocean = (char *)haystack;
	fish = (char *)needle;
	if(!*needle )
	return(ocean);
	while (len-- && *ocean)
	{
		while ((*fish && *ocean) && (*ocean == *fish))
		{
			ocean++;
			fish++;
			i++;
		}
		ocean -= i;
		i = 0;
		if (!*fish)
			return (ocean);
		ocean++;
		fish = (char *)needle;
	}
	return (NULL);
}

// int	main(void)
// {
// char haystack[30] = "MZIRIBMZIRIBMZE123";
// 	char needle[10] = "MZIRIBMZE";
// 	char * empty = (char*)"";
// 	empty = ft_strnstr(haystack,needle,ft_strlen(haystack));
// 	printf("%s",empty);
// }

