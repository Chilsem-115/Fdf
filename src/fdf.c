#include <stdio.h>
#include "load_map.c"
#include "../include/fdf_libs.h"

void	grab_map(char *file_name, char **buffer)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("couldn't open the file");
		*buffer = NULL;
		return ;
	}
	read_file(fd, buffer);
	close(fd);
	load_map(*buffer);
}

int	main(int argc, char **argv)
{
	char	*buffer;

	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s <file>\n", argv[0]);
		return (0);
	}
	grab_map(argv[1], &buffer);
	if (!buffer)
	{
		fprintf(stderr, "Failed to read file or buffer is NULL\n");
		return (1);
	}
	return (0);
}
