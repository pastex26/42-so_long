/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:24:00 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/01/14 08:16:47 by lmarcucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_dvector
{
	double		x;
	double		y;
}				t_dvector;

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_image
{
	void		*pnt;
	char		*pixels;
	t_vector	size;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_mlx_data
{
	void		*co;
	void		*win;
}				t_mlx_data;

typedef struct s_tile
{
	int			id;
	t_vector	pos;
}				t_tile;

typedef struct s_map
{
	t_tile		*map_tab;
	t_vector	map_size;
	char		*map;
}				t_map;

typedef struct s_enemy
{
	int			dir;
	char		behavior;
	t_vector	last_pos;
	t_vector	pos;
}				t_enemy;

typedef struct s_player
{
	t_vector	pos;
	t_vector	last_pos;
	t_vector	sprite_nb;
}				t_player;

typedef struct s_coin
{
	t_bool		active;
	t_vector	pos;
}				t_coin;

typedef struct s_sprite
{
	t_image		u_coin;
	int			coin_sprite;
	t_image		u_player;
	t_image		**player;
	t_image		*coin;
	t_image		enemy;
	t_image		wall;
	t_image		empty;
	t_image		exit;
}				t_sprite;

typedef struct s_game
{
	t_bool		playing;
	t_mlx_data	data;
	t_map		map;
	t_player	player;
	t_enemy		*enemy;
	t_coin		*coin;
	t_sprite	sprite;
	size_t		score;
	long		last_frame;
	int			tile_size;
}				t_game;

# define WIN_TITLE "So_long"

# ifndef WIN_SIZE
#  define WIN_SIZE 2000
# endif

// FPS in milisec
# define FRAME 333

// coin sprites
# define COIN1 "img/coin/coin1.xpm"
# define COIN2 "img/coin/coin2.xpm"
# define COIN3 "img/coin/coin3.xpm"

// map sprites
# define WALL "img/map/wall.xpm"
# define EMPTY "img/map/empty.xpm"
# define EXIT "img/map/exit.xpm"

// enemy sprites
# define ENEMY "img/enemy/enemy.xpm"

// player sprites
# define PLAYERUP1 "img/player/player_back1.xpm"
# define PLAYERUP2 "img/player/player_back2.xpm"
# define PLAYERDOWN1 "img/player/player_front1.xpm"
# define PLAYERDOWN2 "img/player/player_front2.xpm"
# define PLAYERRIGHT1 "img/player/player_right1.xpm"
# define PLAYERRIGHT2 "img/player/player_right2.xpm"
# define PLAYERLEFT1 "img/player/player_left1.xpm"
# define PLAYERLEFT2 "img/player/player_left2.xpm"

// init
t_vector		get_map_size(char *map);
t_bool			init_map(t_game *g, char *file_path);
t_bool			init_coin(t_game *game, char *map);
t_bool			init_enemy(t_game *g);
t_bool			init_player(t_game *g, t_tile *tile);
t_bool			init_game(t_game *game, char *map_file);

// game
void			move_enemy(t_enemy *enemy, t_tile *tile);
t_bool			move_player(t_game *g, int key);
t_bool			check_collision(t_game *g);
t_bool			check_enemy_collide(t_vector p_pos, t_vector pl_pos,
					t_enemy *enemy);

// map
t_bool			check_map_letter(char *map);
t_bool			check_path(t_tile *tile, t_vector size);
t_bool			check_map(t_map *map, t_vector size, int fd);
int				open_fd(char *file);
char			*read_fd(int fd);

// sprite
void			update_animation(t_game *g);
t_image			resize_mlx_image(void *mlx_ptr, t_image *src_img,
					int tile_size);

// draw
void			put_score(t_game *g);
void			draw_player(t_game *g);
void			draw_map(t_game *g);
void			draw_enemy(t_game *g);
void			draw_all(t_game *g);

// secure
void			free_player_sprite(t_image **player);
void			free_player(t_mlx_data *data, t_image **player);
void			free_coin(t_game *g);
void			free_map(t_map *map);
void			free_map_sprite(t_game *g);
void			free_mlx(t_mlx_data *data);
void			free_pathfinding(int **visited, t_vector size);
void			free_all(t_game *g);

// utils
t_tile			get_tile(t_tile *map, int c);
long			get_time_ms(void);
int				tile_id(t_tile *tile, int x, int y);
t_bool			ft_mlx_xpm(t_image *img, t_mlx_data *data, char *path,
					int size);
void			ft_mlx_itow(t_image *img, t_mlx_data *data, t_vector pos);

#endif
