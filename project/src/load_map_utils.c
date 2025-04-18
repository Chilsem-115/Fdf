#include "../inc/fdf_structs.h"
#include "../inc/fdf_libs.h"

t_vertex	**create_vertices(int num_vertices)
{
	t_vertex	**vertices;
	int			i;

	vertices = (t_vertex **)malloc(num_vertices * sizeof(t_vertex*));
	if (!vertices)
		return (NULL);
	i = 0;
	while (i < num_vertices)
	{
		vertices[i] = (t_vertex *)malloc(sizeof(t_vertex));
		if (!vertices[i])
		{
			while(i > 0)
				free(vertices[--i]);
			free(vertices);
			return (NULL);
		}
		i++;
	}
	return (vertices);
}

void	set_values(int x, int y, int z, t_vertex **vertices,int v_index)
{
	vertices[v_index]->location.x = (float)x;
	vertices[v_index]->locaiton.y = (float)y;
	vertices[v_index]->location.z = (float)z;
}

int		next_param(int i, int *y,char *buffer)
{
	if (buffer[i] == '\n')
	{
		(*y)++;
		return (i + 1);
	}
	// skip whitespaces
	while(buffer[i] && (buffer[i] == ' ' || buffer[i] == '\t'))
		i++;
	// skip the token, but stops at new line
	while (buffer[i] && buffer[i] > 32 && buffer[i] != '\n')
		i++;
	return (i);
}

t_vertex	**grab_map(char *buffer, int word_count)
{
	t_vertex	**vertices;
	int			i;
	int			x;
	int			y;
	int			v_index;

	i = 0;
	y = 0;
	v_index = 0;
	vertices = create_vertices(word_count);
	if (!vertices)
		return (NULL);
	while (buffer[i]) // starts the loop until the end of my buffer
	{
		x = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
		{
			set_values(x, y, ft_atoi(buffer + i), vertices, v_index++);
			i = next_param(i, &y, buffer);
			x++;
		}
		if (buffer[i] == '\n')
			i = next_param(i, &y, buffer);
	}
	return (vertices);
}
