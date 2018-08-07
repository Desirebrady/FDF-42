#include "../includes/head.h"

int		exit_mlx(void)
{
	exit(0);
	return (0);
}

static void		read_option(t_wolf *e, int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("Usage : <filename>");
	if (open_file(e, argv[1]) == 0)
		ft_putstr(" <window with map error>");
}

void	text(t_wolf *t)
{
	mlx_string_put(t->mlx.mlx, t->mlx.win, 10, 60,
			0x00ffff, "Press W A S D or the arrow keys to move.");
	mlx_string_put(t->mlx.mlx, t->mlx.win, 10, 80, 0x00ffff, "Press SHIFT to sprint.");
	mlx_string_put(t->mlx.mlx, t->mlx.win, 10, 10,
			0x00ffff, "[Press ESC to quit.]");
}

int				main(int argc, char **argv)
{
	t_wolf	*e;

	e = wolfy();
	read_option(e, argc, argv);
	e->mlx.win = mlx_new_window(e->mlx.mlx, SIZE_X, SIZE_Y,
			"Wolf3d");
	mlx_loop(e->mlx.mlx);
	return (0);
}