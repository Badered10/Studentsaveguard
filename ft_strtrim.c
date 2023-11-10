/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:29:16 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/10 15:49:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char  *ft_strrnstr(const char *first, const char *set , size_t len)
{
  char *ocean;
  char *fish;
  int i ;
  i = 0;
    ocean = (char *)first + ft_strlen(first) - 1;
    fish = (char *)set + ft_strlen(set) - 1;
    if(fish - set == 0 )
    return(ocean);
    while (len-- && (ocean - first != 0))
    {
        while ((fish - set != 0 ) && (*ocean == *fish))
        {
            ocean--;
            fish--;
            i++;
        }
        if (fish - set == 0)
            return (ocean);
        ocean += i;
        i = 0;
        ocean--;
        fish =(char *)set + ft_strlen(set) - 1;
    }
    return NULL;
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *first;
    char	*end;
	char *trim ;
	int diff ;
	
	
    first  = ft_strnstr(s1,set,ft_strlen(s1));
	first += ft_strlen(set);
	end = ft_strrnstr(s1, set , ft_strlen(first));
	diff = end - first ;
	trim = (char*)ft_calloc(diff + 1 ,sizeof(char));
	if(!trim)
	return(NULL);
	ft_memcpy(trim, first , diff);
	return(trim);
}
// int main() {
//   const char str[] = "hello world is good is name is he is cool";
//   const char find[] = "is";
//   char *bo = ft_strtrim(str, find);
//   printf("%s", bo);
//   free(bo);
//   return 0;
// }