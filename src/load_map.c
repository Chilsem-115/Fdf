#include <math.h>
#include "../inc/fdf_structs.h"
#include "../inc/fdf_libs.h"
#include "../inc/load_map.h"

int	get_map_width(char *buffer)
{
	int	i;
    int	count;

    i = 0;
    count = 0;
    while (buffer[i] != '\0')
    {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
	if (buffer[i--] != '\n')
		count++;
    return (count);
}

int	get_map_height()
{
	int	i;
	int	width;
	int	in_word;

	i = 0;
	width = 0;
	in_word = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		if (buffer[i] == ' ' || buffer[i] == '\t')
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				width++;
				in_word = 1;
			}
		}
		i++;
	}
	return (width);
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
	landscape.object.vertex_count = count_word(*buffer);
	landscape.line_count = count_lines(word_count);
	if (line_count == -1)
		return (0);
	landscape.object.vertices = grab_map(*buffer, landscape.object.vertex_count);
	landscape->lines = malloc(sizeof(t_line) * landscape.line_count);
	landscape.lines = generate_lines(landscape, get_map_width(), get_map_height);
}
