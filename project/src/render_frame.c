#include "../inc/render_frame.h"

t_image create_frame(void *mlx_ptr, int width, int height)
{
    t_image new_frame;

    new_img.img_ptr = NULL;
    new_img.img_data = NULL;
    new_img.bpp = 0;
    new_img.size_line = 0;
    new_img.endian = 0;
    new_img.width = width;
    new_img.height = height;

    new_img.img_ptr = mlx_new_image(mlx_ptr, width, height);
    if (!new_img.img_ptr)
        return (new_img);

    new_img.img_data = mlx_get_data_addr(new_img.img_ptr,
                                         &new_img.bpp,
                                         &new_img.size_line,
                                         &new_img.endian);
    return (new_frame);
}

void	render_frame(t_data *data, t_landcape landcape, int vertex_count, t_camera *camera)
{
	t_image	frame;
	t_point	*projected_points;

	frame = create_frame(data->mlx_ptr, data->image.width data->image.height);
	projected_points = calc_position(landscape.object.vertices,
									landscape.object.vertex_count,
									camera);
	if (!projected_points)
	{
		mlx_destroy_image(data->mlx_ptr, frame.img_ptr);
		return ;
	}
	draw_lines(&frame, projected_points, landscape->lines, landscape->line_count);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, frame.img_ptr, 0, 0);
	free(projected_points);
}
