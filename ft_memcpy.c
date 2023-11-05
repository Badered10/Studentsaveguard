/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:31:16 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/04 17:31:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void *ft_memcpy(void *dst, const void *src, size_t _size)
{
    char *source;
    char *destination;
    source = (char *)src;
    destination = (char *)dst;
    while (_size--)
        *destination++ = *source++;
    return(dst);
}
