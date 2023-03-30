/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:44 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 18:26:41 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_move(t_game *game, int y, int x, int keycode)
{
	char	cur;

	cur = game->map[y][x];
	if (keycode != KEY_W && keycode != KEY_S && \
	keycode != KEY_A && keycode != KEY_D)
		return (0);
	if (cur == '1')
		return (0);
	else if (cur == 'C')
	{
		game->collected += 1;
		game->map[y][x] = '0';
	}
	else if (cur == 'E')
	{
		if (game->collected == game->map_textures.collectible)
			close_game(game, 1);
		else
			ft_putstr_fd("There's still a collectible left!\n", 1);
	}
	return (1);
}

int	check_player_move(int keycode, t_game *game)
{
	int	nx;
	int	ny;
	int	flag;

	flag = 1;
	ny = game->position.y;
	nx = game->position.x;
	if (keycode == KEY_W)
		ny--;
	else if (keycode == KEY_S)
		ny++;
	else if (keycode == KEY_A)
		nx--;
	else if (keycode == KEY_D)
		nx++;
	else
		flag = 0;
	flag = check_valid_move(game, ny, nx, keycode);
	if (!flag)
		return (flag);
	if (game->map[game->position.y][game->position.x] == 'E')
		flag = 2;
	game->position.y = ny;
	game->position.x = nx;
	return (flag);
}

void	passing_exit(t_game *game, int prev_y, int prev_x)
{
	draw_pixels_of_tile(game, 'E');
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.img_ptr, prev_x, prev_y);
}

void	draw_update_player(t_game *game, int prev_y, int prev_x)
{
	int		h;
	int		w;

	game->img.data = (int *)mlx_get_data_addr(game->position.img_ptr, \
	&game->img.bpp, &game->img.size_line, &game->img.endian);
	h = 0;
	while (h < TILES)
	{
		w = 0;
		while (w < TILES)
		{
			game->img.data[h * TILES + w] = 0;
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->position.img_ptr, prev_x, prev_y);
	draw_pixels_of_tile(game, 'P');
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->position.img_ptr, game->position.tile_x, game->position.tile_y);
	game->move += 1;
}

int	press_key(int keycode, t_game *game)
{
	int	prev_x;
	int	prev_y;
	int	flag;

	if (keycode == KEY_ESC)
		close_game(game, 1);
	flag = check_player_move(keycode, game);
	if (flag)
	{
		prev_y = game->position.tile_y;
		prev_x = game->position.tile_x;
		if (keycode == KEY_W)
			game->position.tile_y -= TILES;
		else if (keycode == KEY_S)
			game->position.tile_y += TILES;
		else if (keycode == KEY_A)
			game->position.tile_x -= TILES;
		else if (keycode == KEY_D)
			game->position.tile_x += TILES;
		draw_update_player(game, prev_y, prev_x);
		if (flag == 2)
			passing_exit(game, prev_y, prev_x);
		print_move(game->move);
	}
	return (0);
}
