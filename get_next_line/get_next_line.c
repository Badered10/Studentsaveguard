/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:43:49 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/28 13:37:08 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)s + i);
	return (NULL);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l_total;
	size_t	l_sub;

	if (!s)
		return (NULL);
	l_total = ft_strlen(s);
	l_sub = l_total - start;
	if (start > l_total || !len)
		return (ft_strdup("\n"));
	if (len > l_sub)
		len = l_sub;
	if(ft_strchr(s,'\n') != NULL && s[0] != '\n' && s[1] != '\0')
		len += 2;
	else
		len +=1;
	res = (char *)malloc(sizeof(char) * (len));
	// printf("malloc check %zu\n",len);
	if (!res)
		return (free(s),(NULL));
	ft_memmove(res, s + start, len);
	res[len - 1] = '\0';
	// printf("res is %s",res);
	return (res);
}

char	*ft_rest(char *store)
{
	char *nplace;
	char *eplace;
	char *rest;
	int len;

	
	len = 0;
	nplace = ft_strchr(store,'\n');
	eplace = ft_strchr(store,'\0');
	if(!nplace || !eplace)
		return(free(store),(NULL));
	len = (eplace - nplace);
	rest = malloc(sizeof(char) * len);
	if (!rest)
	return (free(store),(NULL));
	// printf("len = %d\n",len);
	ft_memmove(rest,nplace + 1, len);
	rest[len - 1] = '\0';
	// printf("rest %s",rest);
	return (free(store),(rest));
}


char *get_next_line(int fd)
{
    static char *store;
    char		buffer[BUFFER_SIZE + 1];
    char		*res;
    int			check;

	check = 1;
    if (fd < 0 || read(fd,buffer,0) < 0 || BUFFER_SIZE <= 0)
    return ((NULL));
    while (check > 0)
    {
        check = read(fd,buffer,BUFFER_SIZE);
		if (check == -1)
			return (free(store), NULL);
        res = ft_strdup(store);
        free(store);
		buffer[check] = 0;
        store = ft_strjoin(res,buffer);
		if (store[0] == '\0')
			return (free(res),free(store),(NULL));
        free (res);
		if (ft_strchr(store,'\n') != NULL)
			break;
    }
	if (store[0] == '\0')
		return (free(store),(NULL));
    res = ft_strchr(store,'\n');
	if (res)
	check = (res - store);
	else if (ft_strchr(store, '\0') != NULL)
		check = ft_strlen(store);
		// printf("check test %d\n",check);
    res = ft_substr(store,0,check);
	// printf("%s",res);
	store = ft_rest(store);
	// printf("store %s",store);
    return(res);
}
int main()
{
	char *res;
	int fd = open("test.txt",O_CREAT | O_RDWR , 0777);
	
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
	res = get_next_line(fd);
	printf("%s",res);
}