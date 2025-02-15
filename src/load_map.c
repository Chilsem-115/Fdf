#include "../include/fdf_libs.h"
#include "../include/fdf_structs.h"
#include "../lib/lst_lib/ft_lst.h"

t_vertex	**create_vertices(int num_vertices)
{
	t_vertex	**vertices;
	int			i;

	vertices = (t_vertex **)malloc(num_vertices * sizeof(t_vertex*)); if (!vertices)
		return (NULL);
	i = 0;
	while(i < num_vertices)
	{
		vertices[i] = (t_vertex *)malloc(sizeof(t_vertex));
		if (!vertices[i])
			return (NULL);
		i++;
	}
	return (vertices);
}

int count_word(const char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	return (count);
}

set_values()
{
}

void	load_map(char *buffer)
{
	t_vertex	**vertices;
	int			num_vertices;

	num_vertices = count_word(*buffer);
	vertices = create_vertices(num_vertices);
	if (!vertices)
		return ;
	y = 0;
	while (buffer[i] = '\0')
	{
		x = 0;
		while (str[i] = '\n')
		{
			set_values(ft_atoi(str[i]), x, y);
			while(ft_isdigit)
				i++;
			x++;
		}
		y++;
		i++;
	}
}
