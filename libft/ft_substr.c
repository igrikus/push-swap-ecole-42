/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:36 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ret_empty_string(void)
{
	char	*result;

	result = malloc(1);
	if (result == 0)
		return (0);
	*result = 0;
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	count;
	unsigned int	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ret_empty_string());
	if (len > s_len)
		len = s_len;
	count = 0;
	while (count++ < start)
		s++;
	substring = malloc(len + 1);
	if (substring == 0)
		return (0);
	count = 0;
	while (count < len)
	{
		*(substring++) = *(s++);
		count++;
	}
	*substring = 0;
	return (substring - count);
}
