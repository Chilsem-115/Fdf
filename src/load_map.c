#include "../include/fdf_structs.h"
#include "../include/fdf_libs.h"

t_vertex	**load_map(char *file_name, char **buffer)
{
	int			fd;
	t_vertex	**vertices;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_perror("couldn't open the file");
		*buffer = NULL;
		return (NULL);
	}
	read_file(fd, buffer);
	close(fd);
	vertices = grab_map(*buffer);
	return (vertices);
}
