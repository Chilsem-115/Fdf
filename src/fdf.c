#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include "../lib/minilibx/mlx.h"
#include "../inc/load_map.h"
#include "../inc/fdf_structs.h"
#include "../inc/fdf_libs.h"

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
	t_img image;
}	t_data;

int	handle_keypress(int keycode, t_data *data)
{
	if(keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

void	create_window(int height, int width, t_landscape *landscape)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr , height, width, "fdf");

	mlx_key_hook(data.win_ptr, handle_keypress, &data);

	// infinite loop
	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

int	main(int argc, char **argv)
{
	char		*buffer;
	t_landscape	landscape;

	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s <file>\n", argv[0]);
		return (0);
	}
	landscape.object.vertices = load_map(argv[1], &buffer, &landscape);
	if (!landscape.object.vertices)
	{
		fprintf(stderr, "Failed to read file or buffer is NULL\n");
		return (1);
	}
	create_window(600, 800, &landscape); // you first put height and then width
	return (0);
}
