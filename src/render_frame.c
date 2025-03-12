#include "../inc/render_frame.h"

t_image	create_frame();

t_image	render_frame(t_landcape landcape, int vertex_count, t_camera *camera)
{
	t_image	frame;
	t_point	*projected_points;
	int		i;

	frame = create_frame();
	projected_points = calc_position(landscape.object.t_vertex, vertex_count, camera);
	i = 0;
	while (i < vertex_count)
	{
		i++;
	}
	return (frame);
}
