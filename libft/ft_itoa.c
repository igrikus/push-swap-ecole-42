/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:22:15 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_len(int n)
{
	int	len;

	len = 1;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			len++;
	}
	return (len);
}

static char	*get_malloc_array(int n, int size)
{
	char	*array;

	if (n >= 0)
		array = malloc(size + 1);
	else
		array = malloc(size + 2);
	if (array == 0)
		return (0);
	return (array);
}

static void	make_all_job(char *result, int n, int size)
{
	char	symbol;
	int		modulo;

	while (n != 0)
	{
		modulo = n % 10;
		if (modulo < 0)
			modulo *= -1;
		symbol = (char)(modulo + '0');
		*(result + size - 1) = symbol;
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = get_number_len(n);
	result = get_malloc_array(n, size);
	if (result == 0)
		return (0);
	if (n == 0)
	{
		*result = '0';
		*(result + 1) = 0;
		return (result);
	}
	if (n < 0)
		*(result++) = '-';
	make_all_job(result, n, size);
	*(result + size) = 0;
	if (n < 0)
		result--;
	return (result);
}
