#include "../includes/head.h"

void        put_pixels(t_wolf *e, int x, int y, int c)
{
   	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = c;
	e->mlx.pxl[++i] = c >> 8;
	e->mlx.pxl[++i] = c >> 16;
}

int	        put_color(t_wolf *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->color_1);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (e->color_2);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->color_3);
	return (e->color_4);
}

void			drawline(t_wolf *e, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = put_color(e);
	i = -1;
	while (++i < start + e->player.z)
		put_pixels(e, x, i, e->color_sky);
	i--;
	while (++i <= end + e->player.z && i < e->height)
		put_pixels(e, x, i, c);
	i--;
	while (++i < e->height)
		put_pixels(e, x, i, 100);
}