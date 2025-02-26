#include <stdio.h>
#include "load_map.c"
#include "../lib/minilibx/mlx.h"

void		create_window()
{
	void	*mlx_pointer;
	void	*mlx_window;

	mlx_pointer = mlx_init();
	mlx_window = mlx_new_window(mlx_pointer, 500, 500, "my window or something idk");
	mlx_loop(mlx_pointer);
}

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
	char		*buffer;
	t_vertex	vertices;

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
	vertices = load_map(buffer);
	if (!vertices)
	{
		fprintf(stderr, "Failed to read file or buffer is NULL\n");
		return (1);
	}
	create_window();
	return (0);
}
