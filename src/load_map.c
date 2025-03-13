#include <math.h>
#include "../inc/fdf_structs.h"
#include "../inc/fdf_libs.h"
#include "../inc/load_map.h"

int	count_lines(int word_count)
{
	int	size;
    int	sq;

	size = 1;
	sq = size * size;
	while (sq < word_count)
	{
		size++;
		sq = size * size;
	}
	if (sq != word_count)
		(return -1); // not a perfect square
	return (2 * size * (size - 1));
}

void generate_grid_lines(t_landscape *landscape, int width, int height, int line_count)
{
    int x;
    int y;
    int index;
    int line_index;

    line_index = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            index = (y * width) + x;

            /* Connect to the right (horizontal line). */
            if (x < width - 1)
            {
                landscape->lines[line_index].v1 = index;
                landscape->lines[line_index].v2 = index + 1;
                line_index++;
            }

            /* Connect below (vertical line). */
            if (y < height - 1)
            {
                landscape->lines[line_index].v1 = index;
                landscape->lines[line_index].v2 = index + width;
                line_index++;
            }
            x++;
        }
        y++;
    }
    landscape->line_count = line_count;
}

int	**load_map(char *file_name, char **buffer, t_landscape *landscape)
{
	int			fd;
	int			word_count;
	int			line_count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("couldn't open the file");
		*buffer = NULL;
		return (NULL);
	}
	read_file(fd, buffer);
	close(fd);
	word_count = count_word(*buffer);
	line_count = count_lines(word_count);
	if (line_count == -1)
		return (0);
	landscape.object.vertex_count = word_count;
	landscape.object.vertices = grab_map(*buffer, word_count);
	landscape.line_count = line_count;
    landscape->lines = malloc(sizeof(t_line) * line_count);
    if (!landscape->lines)
        return (-1);
	landscape.lines = ;
}
