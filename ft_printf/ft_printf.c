/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:09:06 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/10 21:00:59 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"
# include "libft.h"
int ft_printf(char *string , ...)
{
    int print;
    int count;
    va_list args;
    char *save;

    save = string;
    count = 0;
    va_start(args,string);
    print = 0;

    while (*string)
    {
        if(*string == '%')
        {
            if (!*(++string))
                return 0;
            while (*string)
            {
                if (*string == 's' || c == 'c'|| c == 'i'|| c == 'd'|| c == 'x'|| c == 'X'|| c == 'u'|| c == 'p' || c == '%')
                    flags(*string,save,args);
                string++;
            }
                // if (*string == '-')
                //     mince_flag(string,args);
                // count += specifier(*string,args);
            // else if (*string == '0')
            // else if (*string == '.')
        }
        else
            count += write(1,string,1);
        string++;
    }
    va_end(args);
    return (count);
}
int main()
{
    int i = ft_printf("asa%c",'k');
    printf("%d\n",i);
}