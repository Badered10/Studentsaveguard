/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:43:49 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/27 16:55:02 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
	return(NULL);
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l_total;
	size_t	l_sub;

	if (!s)
		return (NULL);
	l_total = ft_strlen(s);
	l_sub = l_total - start;
	if (start > l_total || !len)
		return (ft_strdup(""));
	if (len > l_sub)
		len = l_sub;
		if(ft_strchr(s,'\n') != NULL)
		len += 2;
		else
		len +=1;
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (NULL);
	ft_memmove(res, s + start, len);
	res[len - 1] = '\0';
	// printf("ressss = %s",res);
	return (res);
}

char *ft_rest(char *store)
{
	char *nplace;
	char *eplace;
	char *rest;
	int len;

	if(!store)
	return(NULL);
	len = 0;
	nplace = ft_strchr(store,'\n');
	eplace = ft_strchr(nplace,'\0');
	// printf("n = %s, e = %s", nplace, eplace);
	len = (eplace - nplace);
	if(!nplace || !eplace)
	return(NULL);
	rest = malloc(sizeof(char) * len);
	ft_memmove(rest,nplace + 1,len);
	free(store);
	// printf("%p\n",rest);
	return (rest);
}


char *get_next_line(int fd)
{
    static char *store;
    char buffer[BUFFER_SIZE + 1];
    char *res;
    int check;

	// if(store)
	// printf("'%s'",store);	
	check = 1;
    if (fd < 0 || read(fd,buffer,0) < 0 || BUFFER_SIZE <= 0)
    return (NULL);

    while (check != 0)
    {
		// printf("ok\n");
		// printf("i am here !!\n");
        check = read(fd,buffer,BUFFER_SIZE);
        if (check <= 0 && !store)
		{
			// printf("nothing to read!\n");
        	return (NULL);
		}
        res = ft_strdup(store);
		if (!res)
		return NULL;
		// printf("\nsotre befor free in main func %s-----",store);
        free(store);
        store = ft_strjoin(res,buffer);
		if (!store)
		{
			printf("FREEE STORE!\n");
			free(res);
			free(store);	
			return (NULL);
		}
		// printf("\nsotre afer join in main func %s------",store);
        free (res);
    }
	// printf("LOOP EXIT !!!!\n");
    res = ft_strchr(store,'\n');
	if(res)
    check = (res - store);
	else if (ft_strchr(store, '\0') != NULL)
	{
		// printf("2");
	check = ft_strlen(store);
	}
    res = ft_substr(store,0,check);
	store = ft_rest(store);
	// printf("adress at end of store %p\n",store);
    return(res);
}
// int main()
// {
// 	char *res;
// 	int fd = open("test.txt",O_CREAT | O_RDWR , 0777);
	
// 	res = get_next_line(fd);
// 	printf("%s",res);
// 	res = get_next_line(fd);
// 	printf("%s",res);
// 	res = get_next_line(fd);
// 	printf("%s",res);
// 	res = get_next_line(fd);
// 	printf("%s",res);
// 	res = get_next_line(fd);
// 	printf("%s",res);
// }