#include <stdio.h>
#include "../lib/minilibx/mlx.h"
#include "../include/load_map.h"
#include "../include/fdf_structs.h"
#include "../include/fdf_libs.h"

void		create_window()
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 1800, 1800, "my window or something idk");
	mlx_loop(mlx_ptr);
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
}

int	main(int argc, char **argv)
{
	char		*buffer;
	t_vertex	**vertices;

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
