#include "minilibx/mlx.h"

int main()
{
	void	*mlx_pointer;
	void	*mlx_window;

	mlx_pointer = mlx_init();
	mlx_window = mlx_new_window(mlx_pointer, 500, 500, "my window or something idk");
	mlx_loop(mlx_pointer);
}
