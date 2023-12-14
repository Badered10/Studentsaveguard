/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:51 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/14 12:14:08 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
static int	hexalenth(unsigned long n)
{
	int	res;
		res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
    return (res);
}
int ft_xsflags(char *string, unsigned int x , char c)
{
    // printf("taqtaq\n");   save_m + 1 "5d okeey",321; nes.len =3; nes.mince = 1;  nes.zero = 0; nes.spces= 7 nes.point = 1 nes.zeros = 5;
    f nes;

    nes.zero = 0;
    nes.mince = 0;
    nes.point = 0;
    nes.spaces = 0;
    nes.zeros = 0;
    nes.count = 0;
    nes.hashtag = 0;
    // printf("string is'%s'\n",string);
    while(*string == '0' && *(string + 1))
    {
        nes.zero = 1;
        string++;
    }
    while (*string == '#' && *(string + 1))
    {
        nes.hashtag = 1;
        string++;
    }
    while(*string == '-' && *(string + 1))
    {
        // printf("hahaha");
        nes.zero = 0;
        nes.mince = 1;
        string++;
    }
    while (*string == '#' && *(string + 1))
    {
        nes.hashtag = 1;
        string++;
    }
    nes.ud = x;
    nes.len += hexalenth(x);
    // printf("lenth %d\n",nes.len);
    if(ft_isdigit(*string))
    {
        nes.spaces = ft_atoi(string);
        //  printf("\t  first set spaces : %d,\n",nes.spaces);   "5d"  int d = 234; zero = 0 , mince = 1; len= 3; sp = 7, point = 1 zeros = 2; 
        if (nes.spaces > nes.len)
        nes.spaces = nes.spaces - nes.len;
        else 
        nes.spaces = 0;
    }
    else
       nes.spaces = 0; 
    while(ft_isdigit(*string))
        string++;
    // printf("\tzero : %d, point %d, mince %d \n",nes.zero , nes.point , nes.mince);
    if (*string == '.' && *(string + 1))
    {
        nes.point = 1;
        string++;
        if(ft_isdigit(*string))
        {                      
            nes.zeros = ft_atoi(string);
            // printf("fresh : zeros %d, spaces %d \n",nes.zeros,nes.spaces);
            if (nes.zeros > nes.len)
            nes.zeros = nes.zeros - nes.len;
            else
            nes.zeros = 0;
            nes.spaces -= nes.zeros;
            // printf("zeros %d, spaces %d \n",nes.zeros,nes.spaces);
        }
        // nes.width = nes.zeros + nes.spaces; to remove
    }
    else if (nes.zero == 1 && nes.point != 1 && nes.mince != 1)
    {
        // printf("done dude!\n");
            nes.zeros = nes.spaces;
    }
        if (nes.zeros == nes.spaces)
            nes.spaces = 0;

    // printf("\t flags  #:%d, -:%d , 0:%d, .:%d \n",nes.hashtag , nes.mince , nes.zero,nes.point);
    if (nes.mince == 1)
    {
        if (nes.hashtag == 1)
        {
           nes.count += write(1,"0x",2);  
           nes.spaces -=2;
        }
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(nes.ud,1 ,c);
        while ((nes.spaces)-- > 0 )
            nes.count += write(1," ",1);
        return (nes.count);
    }
    else if (nes.point == 1)
    {
        if (nes.hashtag == 1)
            nes.spaces -=2;
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        if (nes.hashtag == 1)
            nes.count += write(1,"0x",2);
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(nes.ud,1 ,c);
        return (nes.count);
    }
    else if (nes.hashtag == 1 && nes.zero == 1)
    {
        if (nes.hashtag == 1)
        {
           nes.count += write(1,"0x",2);  
           nes.zeros -=2;
        }
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(nes.ud,1 ,c);
        return (nes.count);
    }
    else if (nes.zero == 1 )
    {
        while ((nes.zeros)-- > 0)
            nes.count += write(1,"0",1);
        nes.count += ft_puthexa_fd(nes.ud,1 ,c);
        return (nes.count);
    }
    else
    {
        while ((nes.spaces)-- > 0)
            nes.count += write(1," ",1);
        nes.count += ft_puthexa_fd(nes.ud,1 ,c);
        return (nes.count);
    }
}
