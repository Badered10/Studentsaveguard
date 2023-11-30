/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:43:49 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/30 15:55:53 by baouragh         ###   ########.fr       */
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
	if (ft_strchr(s, '\n') != NULL && s[0] != '\n' && s[1] != '\0')
		len += 2;
	else
		len += 1;
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (free(s), (NULL));
	ft_memmove(res, s + start, len);
	res[len - 1] = '\0';
	return (res);
}

char	*ft_rest(char *store)
{
	char	*nplace;
	char	*eplace;
	char	*rest;
	int		len;

	len = 0;
	nplace = ft_strchr(store, '\n');
	eplace = ft_strchr(store, '\0');
	if (!nplace || !eplace)
		return (free(store), (NULL));
	len = (eplace - nplace);
	if (len)
		rest = malloc(sizeof(char) * len);
	else
		return (free(store), (NULL));
	if (!rest)
		return (free(store), (NULL));
	ft_memmove(rest, nplace + 1, len);
	rest[len - 1] = '\0';
	return (free(store), (rest));
}

char	*get_store(int fd, char *store, char *res, char *buffer)
{
	int	check;

	check = 1;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(store),free(buffer),NULL);
	while (check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == 0 && ((!store) || (store[0] == '\0')))
			return (free(store),free(buffer),NULL);
		if (check == -1)
			return (free(store),free(buffer),NULL);
		buffer[check] = 0;
		res = ft_strdup(store);
		if (store)
			free(store);
		store = ft_strjoin(res, buffer);
		if (store[0] == '\0' && res)
			return (free(res), free(store),free(buffer),(NULL));
		if (res)
			free(res);
		if (ft_strchr(store, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	char		*res;
	int			check;

	res = NULL;
	check = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buffer)
		return(free(store),NULL);
	store = get_store(fd, store, res, buffer);
	if (!store)
		return (NULL);
	if (store[0] == '\0')
		return (free(store), (NULL));
	res = ft_strchr(store, '\n');
	if (res)
		check = (res - store);
	else if (ft_strchr(store, '\0') != NULL)
		check = ft_strlen(store);
	res = ft_substr(store, 0, check);
	store = ft_rest(store);
	return (res);
}

int main()
{
	char *res;
	int fd1;
	
	fd1 = open("2.txt", O_RDONLY , 0777);
	res = get_next_line(fd1);
	printf("%s",res);
	res = get_next_line(fd1);
	printf("%s",res);
}