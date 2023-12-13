/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:31:57 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/13 14:31:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenth(unsigned long n)
{
	int	res;

	res = 1;
	if (n > 0)
		res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*alloc(int res)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * res + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, res + 1);
	return (str);
}

static void	fill(char *str, int num, unsigned long n , char c)
{
	int		j;
	unsigned long	x;
	char *base;

	if (c =='x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	x = n;
	j = 0;
	num -= 1;
	if (num < 16)
	{
		printf("%d",num);
		str[num] = base[x % 16];
			num--;
	}
	else
	{
		fill(str,num,x/16,c);
		fill(str,num,x%16,c);
	}
}

char	*ft_itohexa(unsigned long n , char c)
{
	char	*res;
	int		num;

	num = lenth(n);
	res = alloc(num);
	if (!res)
		return (NULL);
	fill(res, num, n, c);
	return (res);
}

// int	ft_putptr_fd(void *s, int fd,)
// {
// 	int count;

// 	count = 0;
// 	if ((fd < 0) || !s)
// 		return (-1);
// 	count += write(fd, s, ft_strlen(s));
// 	return (count);
// }

int main()
{
	char *s ;
	s = ft_itohexa(46454231, 'x');
	printf("%s\n",s);
}