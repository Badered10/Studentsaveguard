/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mince_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:00:25 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/02 18:57:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h" 

int mince_flag(char *string, va_list args)
{
    size_t len;
    int blank;
    int spaces;
    int zeros;

    blank = 0;
    
    while(*string == '-' && *(string + 1))
            string++;
    while(*string == '0' && *(string + 1))
        string++;
    if(ft_isdigit(*string))
    {
        spaces = ft_atoi(string);
        blank = spaces - len;
    }
    while(ft_isdigit(*string))
        string++;
    if (*string == '.' && *(string + 1))
    {
        string++;
        if(ft_isdigit(*string))
        {                       //// check % found! --> skip -  >> skip 0 >>>> if found number >> save it (number - len of string) >>> skip all number >> if . found skip it  >> check if thers is number >> svae it 
                                            // >>               
            zeros = ft_atoi(string); //// "%--------------000000011.4s" string "hello"
            if(zeros >= len)
                print = len;
            else
                print = zeros;
        }
    }   
        while (blank-- >= 0)
            count += write(1," ",1);
}