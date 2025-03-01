#include <stdio.h>
#include "../lib/minilibx/mlx.h"
#include "../include/load_map.h"
#include "../include/fdf_structs.h"
#include "../include/fdf_libs.h"

void		create_window(int height, int width)
{
	void	*mlx;
	void	*win;
	int x, y;

	mlx = mlx_init();
	win = mlx_new_window(mlx , height, width, "fdf");


	for (int i = 0; i < 100; i++)
    {
        x = rand() % 800; // Random x between 0 and 799
        y = rand() % 600; // Random y between 0 and 599
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF); // White color
    }
	// infinite loop
	mlx_loop(mlx );

	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
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
	create_window(1200, 1800); // you first put height and then width
	return (0);
}
