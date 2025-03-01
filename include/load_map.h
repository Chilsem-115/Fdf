#ifndef LOAD_MAP_H
# define LOAD_MAP_H

# include "fdf_structs.h"

t_vertex	**create_vertices(int num_vertices);
int			count_word(const char *str);
void		set_values(int x, int y, int z, t_vertex **vertices, int v_index);
int			next_param(const char *buffer, int i);
t_vertex	**fetch_string(char *buffer);

#endif
