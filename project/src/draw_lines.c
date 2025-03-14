#include "../inc/fdf_libs.h"

int		classify_line(int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	absolute_x;
	int	absolute_y;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		absolute_x = -dx;
	else
		absolute_x = dx;
	if (dy < 0)
		absolute_y = -dy;
	else
		absolute_y = dy;
	if (dx == 0 || absolute_y > absolute_x)
	{
		if (dy >= 0)
			return (0);
		return (1);
	}
	if (dy >= 0)
		return (2);
	return (3);
}

void	draw_lines()
{
	int	identifier; // this number will decide what the line will be

	identifier = classify_line();
	if (identifier == 0)
		draw_steep_positive(); // steep + positive
	else if (identifier == 1)
		draw_steep_negative(); //steep + negative
	else if (identifier == 2)
		draw_shallow_positive(); // shallow + positive
	else if (identifier == 3)
		draw_shallow_negative(); // shallow + negative
}
