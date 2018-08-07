#include "../includes/head.h"

static void		draw_ray(t_wolf *e, int x)
{
	int		height;
	int		draw_start;
	int		draw_end;

	height = (int)(e->height / e->ray.dist);
	draw_start = -height / 2 + e->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = height / 2 + e->height / 2;
	if (draw_end >= e->height)
		draw_end = e->height - 1;
	drawline(e, x, draw_start, draw_end);
}

static void		cal_ray_dist(t_wolf *e)
{
	while (e->ray.hit == 0)
	{
		if (e->ray.side.x < e->ray.side.y)
		{
			e->ray.side.x += e->ray.delta.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.hit_side = 0;
		}
		else
		{
			e->ray.side.y += e->ray.delta.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.hit_side = 1;
		}
		if (e->map[e->ray.map.x][e->ray.map.y] > 0)
		{
			e->ray.hit = 1;
			if (e->ray.hit_side == 0)
				e->ray.dist = (e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x)
						/ 2) / e->ray.dir.x;
			else
				e->ray.dist = (e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y)
						/ 2) / e->ray.dir.y;
		}
	}
}

static void		ray_side_step(t_wolf *e)
{
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.side.x = (e->ray.pos.x - (int)e->ray.pos.x) * e->ray.delta.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.side.x = ((int)e->ray.pos.x + 1 - e->ray.pos.x) * e->ray.delta.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.side.y = (e->ray.pos.y - (int)e->ray.pos.y) * e->ray.delta.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.side.y = ((int)e->ray.pos.y + 1 - e->ray.pos.y) * e->ray.delta.y;
	}
}

static void		start_ray(t_wolf *e, int x)
{
	e->ray.map.x = (int)e->ray.pos.x;
	e->ray.map.y = (int)e->ray.pos.y;
	e->ray.cam = 2 * x / (double)e->width - 1;
	e->ray.dir.x = e->player.dir.x + e->player.plane.x * e->ray.cam;
	e->ray.dir.y = e->player.dir.y + e->player.plane.y * e->ray.cam;
	e->ray.delta.x = sqrt(1 + (e->ray.dir.y * e->ray.dir.y) /
			(e->ray.dir.x * e->ray.dir.x));
	e->ray.delta.y = sqrt(1 + (e->ray.dir.x * e->ray.dir.x) /
			(e->ray.dir.y * e->ray.dir.y));
	e->ray.hit = 0;
	e->ray.dist = -1;
	e->ray.hit_side = -1;
}

void			ray_cast(t_wolf *e)
{
	int		x;

	x = -1;
	e->ray.pos.x = e->player.pos.x;
	e->ray.pos.y = e->player.pos.y;
	while (++x < e->width)
	{
		start_ray(e, x);
		ray_side_step(e);
		cal_ray_dist(e);
		draw_ray(e, x);
	}
}