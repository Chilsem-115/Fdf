#include "../inc/fdf_libs.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr && old_size > 0)
		ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

int	read_into_buffer(int fd, char **buffer, size_t buffer_size, size_t *total_read)
{
	ssize_t bytes_read;

	bytes_read = read(fd, *buffer + *total_read, buffer_size - *total_read - 1);
	if (bytes_read < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	*total_read += bytes_read;
	return (1);
}

void	read_file(int fd, char **buffer)
{
	size_t	buffer_size;
	size_t	total_read;
	int		status;

	total_read = 0;
	buffer_size = BUFFER_SIZE;
	*buffer = malloc(buffer_size);
	if (!(*buffer))
		return ;
	while (1)
	{
		if (total_read + 1 >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			*buffer = ft_realloc(*buffer, total_read, buffer_size);
			if (!(*buffer))
				return ;
		}
		status = read_into_buffer(fd, buffer, buffer_size, &total_read);
		if (status <= 0)
			break ;
	}
	(*buffer)[total_read] = '\0';
}
