/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:43 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr_spec(const char *s, int c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == c)
		return ((char *) s);
	return (0);
}

size_t	ft_strlen_symbol(const char *s, char stop_symbol)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] && s[len] != stop_symbol)
		len++;
	return (len);
}

char	*strjoin_spec(char *s1, char const *s2)
{
	char			*result;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	total_len;

	s1_len = ft_strlen_symbol(s1, 0);
	s2_len = ft_strlen_symbol(s2, 0);
	total_len = s1_len + s2_len;
	result = malloc(total_len + 1);
	if (result == 0)
		return (0);
	while (s1_len && *s1)
		*(result++) = *(s1++);
	while (*s2)
		*(result++) = *(s2++);
	*result = 0;
	if (s1)
		free(s1 - s1_len);
	return (result - total_len);
}

char	*substr_spec(char *s, unsigned int start, size_t len, int is_free_need)
{
	char			*substring;
	unsigned int	count;
	unsigned int	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen_symbol(s, 0);
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
	if (is_free_need)
		free(s - (start + count));
	return (substring - count);
}
