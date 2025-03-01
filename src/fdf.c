#include <stdio.h>
#include "../lib/minilibx/mlx.h"
#include "../include/load_map.h"
#include "../include/fdf_structs.h"
#include "../include/fdf_libs.h"

void		create_window(int height, int width)
{
	void	*mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, height, width, "fdf");

	// infinite loop
	mlx_loop(mlx_connection);

	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
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
	vertices = load_map(argv[1], &buffer);
	if (!vertices)
	{
		fprintf(stderr, "Failed to read file or buffer is NULL\n");
		return (1);
	}
	create_window(1800, 1800); // you first put height and then width
	return (0);
}
