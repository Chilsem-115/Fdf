#include "../inc/fdf_structs.h"
#include "../inc/fdf_libs.h"
#include "../inc/load_map.h"

t_vertex	**load_map(char *file_name, char **buffer)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("couldn't open the file");
		*buffer = NULL;
		return (NULL);
	}
	read_file(fd, buffer);
	close(fd);
	return (grab_map(*buffer));
}
