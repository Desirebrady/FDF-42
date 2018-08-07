#ifndef HEAD_H
#define HEAD_H

#define CREATE_IMAGE mlx_get_data_addr

# define SIZE_Y 800
# define SIZE_X	800
# include <stdlib.h>
#include "../libft/libft.h"
# include <math.h>
# include <time.h>
# include <mlx.h>
# define COLOR 0x00FFFF


typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				s_line;
	int				ed;
	clock_t			last_frame;
	clock_t			next_frame;
}					t_mlx;

typedef struct		s_wolf
{
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	int				start_x;
	int				start_y;
}					t_wolf;
					

t_mlx		*object_mlx(void);
//t_img		*create_img(t_mlx *obj);
int			update(int keycode, t_wolf *tmp);
void 		initializekeyboard(t_wolf *wolf);
int 		keyreleased(int key, t_wolf *wolf);
void		onguikeyboard(t_wolf *wolf);
int			keypressed(int key, t_wolf *wolf);
void		text(t_wolf *t);
t_wolf 		*wolfy(void);
void		drawline(t_wolf *wolfy, int x, int start, int end);
int	        put_color(t_wolf *wolfy);
void        put_pixels(t_wolf *wolfy, int x, int y, int color);
void        perform_dda(t_wolf  *wolfy);
void		ray_cast(t_wolf *e);
void        perform_ray_cast(t_wolf *wolfy);
void		init_player(t_wolf *wolfy);
//void		init_mlx(t_wolf *wolfy);
int			open_file(t_wolf *e, char *f);
#endif