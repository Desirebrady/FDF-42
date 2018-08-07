#include "../includes/head.h"

t_mlx	*object_mlx(void)
{
	t_mlx		*new;

	new = (t_mlx*)malloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, SIZE_X, SIZE_Y, "Wolf3D");
	return (new);
}