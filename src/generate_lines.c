#include <math.h>
#include "../inc/fdf_structs.h"
#include "../inc/fdf_libs.h"
#include "../inc/load_map.h"

static void add_horizontal_line(t_landscape *landscape, int index, int *line_index)
{
    landscape->lines[*line_index].v1 = index;
    landscape->lines[*line_index].v2 = index + 1;
    (*line_index)++;
}

static void add_vertical_line(t_landscape *landscape, int index, int width, int *line_index)
{
    landscape->lines[*line_index].v1 = index;
    landscape->lines[*line_index].v2 = index + width;
    (*line_index)++;
}

void generate_lines(t_landscape *landscape, int width, int height)
{
    int line_index;
	int	index;
    int x;
	int y;

	line_index = 0;
	y = 0;
    while (y < height)
	{
		x = 0;
        while (x < width)
		{
			index = y * width + x;
            if (x < width - 1)
                add_horizontal_line(landscape, index, &line_index);
            if (y < height - 1)
                add_vertical_line(landscape, index, width, &line_index);
			x++
        }
		y++
    }
}
