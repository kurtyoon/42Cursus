/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:28:13 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 18:28:15 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# define TILES 64
# define X_EVENT_KEYPRESS 2
# define X_EVENT_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_param
{
	int		x;
	int		y;
	int		tile_x;
	int		tile_y;
	void	*img_ptr;

}	t_param;

typedef struct s_map
{
	int	wall;
	int	player;
	int	collectible;
	int	exit;
}		t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			collected;
	int			move;
	t_param		position;
	t_img		img;
	t_map		map_textures;
	char		**map;
	int			valid_path;
}	t_game;

typedef struct s_check
{
	int	y;
	int	x;
	int	collectible;
	int	**visited;
}	t_check;

// utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);

// path.c
int		check_valid_move(t_game *game, int x, int y, int keycode);
int		check_player_move(int keycode, t_game *game);
void	passing_exit(t_game *game, int prev_x, int prev_y);
void	draw_update_player(t_game *game, int prev_x, int prev_y);
int		press_key(int keycode, t_game *game);

// init.c
void	init_minilibx(t_game *game);
void	init_param(t_game *game);
void	get_map_line(t_game *game, char *line, int y);
void	init_map(t_game *game, int fd);
int		check_last_line(char *line);

// map.c
void	set_map_value(t_game *game, char component);
void	check_map_line(t_game *game, char *line, int check_wall);
void	check_map_components(t_game *game);
void	get_map(t_game *game, int fd);

// draw.c
void	draw_pixels_of_tile(t_game *game, char texture);
void	draw_map(t_game *game, char *line, int y);

// player.c
int		close_game(t_game *game, int type);
int		close_game_with_error(int type);
void	print_move(char c);

void	check_map_path(t_game *game);

#endif
