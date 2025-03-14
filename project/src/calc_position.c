#include <math.h>
#include "../inc/fdf_structs.h"

t_3d_location	apply_camera_location(t_3d_location pos, t_camera *camera)
{
	pos.x = pos.x - camera->location.x;
	pos.y = pos.y - camera->location.y;
	pos.z = pos.z - camera->location.z;
	return (pos);
}

t_3d_location	apply_camera_rotation(t_3d_location pos, t_camera *camera)
{
	float	rx;
	float	ry;
	float	rz;
	float	temp_x;
	float	temp_y;
	float	temp_z;

	rx = camera->rotation.rot_x; // we apply rotation
	ry = camera->rotation.rot_y;
	rz = camera->rotation.rot_z;
	temp_y = (pos.y * cosf(rx)) - (pos.z * sinf(rx)); // rotating around x axis
	temp_z = (pos.y * sinf(rx)) + (pos.z * cosf(rx));
	pos.y = temp_y;
	pos.z = temp_z;
	temp_x = (pos.x * cosf(ry)) + (pos.z * sinf(ry)); // rotating around y axis
	temp_z = (-pos.x * sinf(ry)) + (pos.z * cosf(ry));
	pos.x = temp_x;
	pos.z = temp_z;
	temp_x = (pos.x * cosf(rz)) - (pos.y * sinf(rz)); // rotating around z axis
	temp_y = (pos.x * sinf(rz)) + (pos.y * cosf(rz));
	pos.x = temp_x;
	pos.y = temp_y;

	return (pos);
}

t_point	project_to_2d(t_3d_location pos);
{
	t_point result;
	float	iso_x;
	float	iso_y;

	iso_x = (pos.x - pos.y) * cosf(M_PI / 6.0f);
	iso_y = (pos.x + pos.y) * sinf(M_PI / 6.0f) - pos.z;
	result.x = (int)iso_x;
	result.y = (int)iso_y;

	return (result);
}

t_point	*calc_position(t_vertex *vertices, int vertex_count, t_camera *camera)
{
	t_point	*points;
	t_3d_location local_pos;
	int		i;

	points = 0;
	i = 0;
	points = malloc(sizeof(t_point) * vertex_count);
	if (!points)
		return (0);
	while(i < vertex_count)
	{
		local_pos = vertices[i].location;
		local_pos = apply_camera_location(local_pos, camera);
		local_pos = apply_camera_rotation(local_pos, camera);
		points[i] = project_to_2d(local_pos);
		i++;
	}
	return (points);
}
