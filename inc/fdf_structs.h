#ifndef FDF_STRUCTS_H
#define FDF_STRUCTS_H

typedef	struct s_3d_location
{
	float x;
	float y;
	float z;
}	t_3d_location;

typedef struct s_3d_rotation
{
	float	rot_x;
	float	rot_y;
	float	rot_z;
}	t_3d_rotation;

typedef struct s_vertex
{
	t_3d_location	location;
}	t_vertex;

typedef struct s_line
{
	int	v1; //this is for the first vertex
	int	v2;	//this is for the second vertex
}	t_line;

typedef struct s_camera
{
	t_3d_location	location;
	t_3d_rotation	rotaiton;
}	t_camera;

typedef struct s_object
{
	t_3d_location	location; // location and rotation storing
	t_3d_rotation	rotation;
	t_vertex		*vertices; // Array of vertices
	int				vertex_count;
}	t_object;

typedef struct s_landscape
{
	t_object	object;
	t_line		*lines;
	int			line_count;
}	t_landscape;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	image;
}	t_data;

typedef struct s_point
{
	int	x;
	int y;
}	t_point;

#endif
