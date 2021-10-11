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

int	return_func(char **remainder, ssize_t bytes_read)
{
	if (*remainder == 0)
		return (-1);
	if (bytes_read > 0)
		return (1);
	if (bytes_read == 0)
	{
		free(*remainder);
		*remainder = 0;
	}
	return ((int) bytes_read);
}

char	*get_rem_with_slash_n(char *remainder, char *buf,
							  int fd, ssize_t *bytes_read)
{
	*bytes_read = 1;
	while (*bytes_read > 0)
	{
		if (strchr_spec(remainder, '\n'))
			break ;
		*bytes_read = read(fd, buf, 48);
		if (*bytes_read == -1)
			break ;
		buf[*bytes_read] = 0;
		remainder = strjoin_spec(remainder, buf);
		if (remainder == 0)
		{
			free(buf);
			return (0);
		}
	}
	free(buf);
	return (remainder);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		bytes_read;
	char		*buf;
	static char	*remainder;
	size_t		n_len;

	buf = malloc(48 + 1);
	if (buf == 0)
		return (-1);
	remainder = get_rem_with_slash_n(remainder, buf, fd, &bytes_read);
	if (remainder == 0)
		return (-1);
	n_len = ft_strlen_symbol(remainder, '\n');
	*line = substr_spec(remainder, 0, n_len, 0);
	if (*line == 0)
	{
		free(remainder);
		return (-1);
	}
	remainder = substr_spec(remainder, n_len + 1,
			ft_strlen_symbol(remainder, 0) - n_len, 1);
	return (return_func(&remainder, bytes_read));
}
