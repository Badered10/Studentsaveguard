/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:29:16 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/10 17:11:39 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */






// string = ABCDEFGH;
// find = GH;








#include "libft.h"

static char  *ft_strrnstr(const char *first, const char *set , size_t len)
{
  char *ocean;
  char *fish;
  int i ;
  i = 0;
	
	ocean = (char *)first + ft_strlen(first);
  if(!*first && !*set)
    return((char *)first);
	if(!*set)
	return(ocean);
	if(!*first)
	return NULL;
    ocean = (char *)first + ft_strlen(first) - 1;
    fish = (char *)set + ft_strlen(set) - 1;
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
	if((end && first) && first != end)
	diff = end - first ;
	if(end == first)
	diff = ft_strlen(first);
	if(!end || !first)
	return NULL;
	trim = (char*)ft_calloc(diff + 1 ,sizeof(char));
	if(!trim)
	return(NULL);
	ft_memcpy(trim, first , diff);
	return(trim);
}
int main() {
  char *b = ft_strtrim("   xxxtripouille x  x  xdasdasd", " x");
  printf("%s", b);
  free(b);
  return 0;
}