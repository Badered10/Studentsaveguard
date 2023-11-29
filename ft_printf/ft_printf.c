/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/29 18:31:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"
int ft_printf(char *string)
{
    int number_of_soz;
    int number_after_p;
    size_t len;
    int blank;
    int print;
    int count;

    blank = 0;
    print = 0;
    len = ft_strlen(string);
    while (*string)
    {
        if(*string == '%')
        {
            *string++;
            if (*string == '-')
            {
                while(*string == '-')
                string++;
                while(*string == '0')
                string++;
                if(ft_isdigit(*string))
                {
                    number_of_soz = ft_atoi(string);
                    blank = number_of_soz - len;
                }
                while(ft_isdigit(*string))
                    string++;
                if (*string == '.')
                {
                    string++;
                    if(ft_isdigit(*string))
                    {
                        number_after_p= ft_atoi(string);
                        if(number_after_p >= len)
                        print = len;
                        else
                        print = number_after_p;
                    }
                    if(*string == 's')
                }
                
                while (blank-- >= 0)
                count += write(1,' ',1);
                
            }
            if (*string == '0')
            if (*string == '.')
        }
        count += write(1,*string,1);
        string++;
    }
}