#include <math.h>

t_point	isometric_projection(int x, int y, int z)
{
    t_point p;
    double angle;
	angle = M_PI / 6;
    p.x = (int)((x - y) * cos(angle));
    p.y = (int)((x + y) * sin(angle) - z);
    return (p);
}

void	draw_line(int x1, int y1, int x2, int y2)
{
	if (x2 < x1)
	{
	}
}
