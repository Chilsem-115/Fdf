#ifndef FDF_LIBS_H
#define FDF_LIBS_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 128
void	read_file(int fd, char **buffer);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_atoi(char *str);

#endif
