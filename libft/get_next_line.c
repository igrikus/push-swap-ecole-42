#include "libft.h"

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
