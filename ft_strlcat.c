/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:41:41 by baouragh          #+#    #+#             */
/*   Updated: 2023/11/05 15:41:44 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"

size_t ft_strlcat(char * dst, const char *src, size_t dstsize)
{
    char *source;
    source = (char *)src;
    size_t source_lenth;

    source_lenth = ft_strlen(source);
    // dst_size = ft_strlen(dst) + 1;

    while(dstsize)
}