/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:56:27 by baouragh          #+#    #+#             */
/*   Updated: 2023/12/11 09:53:57 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void c_specifier()
{
    
}

void flags(char specifier ,char *string ,va_list args)
{
       if (specifier == 'c')
        c_specifier();
}