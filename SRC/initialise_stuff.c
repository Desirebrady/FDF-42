
#include "../includes/head.h"


void		init_player(t_wolf *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
}

static void		init_mlx(t_wolf *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.img = mlx_new_image(e->mlx.mlx, SIZE_X, SIZE_Y);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
			&(e->mlx.ed));
}

t_wolf 			*wolfy(void)
{
	t_wolf	*e;

	
	e = (t_wolf *)malloc(sizeof(t_wolf));
	if (e == NULL)
		ft_putstr("malloc error");
	e->width = SIZE_X;
	e->height = SIZE_Y;
	init_player(e);
	init_mlx(e);
	e->color_1 = 0xff9600;
	e->color_2 = 0x73ff00;
	e->color_3 = 0xff00fc;
	e->color_4 = 0x46fffc;
	e->color_sky = 0x00cdff;
	e->color_ground = 0x2700ff;
	return (e);
}