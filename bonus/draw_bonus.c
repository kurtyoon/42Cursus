/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:28:03 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 18:29:33 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	draw_pixels_of_tile(t_game *game, char texture)
{
	int	w;
	int	h;

	if (texture == '1')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/wall.xpm", &w, &h);
	else if (texture == 'C')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/collectible.xpm", &w, &h);
	else if (texture == 'E')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/exit.xpm", &w, &h);
	else if (texture == '0')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/empty.xpm", &w, &h);
	else if (texture == 'P')
	{
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/player.xpm", &w, &h);
		game->position.img_ptr = game->img.img_ptr;
	}
}

void	draw_map(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '0')
		{
			x++;
			continue ;
		}
		if (line[x] == 'P')
		{
			game->position.tile_x = x * TILES;
			game->position.tile_y = y * TILES;
		}
		draw_pixels_of_tile(game, line[x]);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.img_ptr, x * TILES, y * TILES);
		x++;
	}
}
