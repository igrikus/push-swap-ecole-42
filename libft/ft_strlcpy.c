/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:20 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	if (dst == 0 || src == 0)
		return (0);
	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (*src && (i < dstsize - 1))
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	*dst = 0;
	return (res);
}
