/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:28:03 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 13:59:01 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_pixels_of_tile(t_game *game, char texture)
{
	int	w;
	int	h;

	if (texture == '1') // '1'일 경우 벽
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/wall.xpm", &w, &h);
	else if (texture == 'C') // 'C'일 경우 콜렉터블
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/collectible.xpm", &w, &h);
	else if (texture == 'E') // 'E'일 경우 출구
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/exit.xpm", &w, &h);
	else if (texture == '0') // '0'일 경우 빈공간
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/empty.xpm", &w, &h);
	else if (texture == 'P') // 'P'인 경우 플레이어
	{
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
				"imgs/player.xpm", &w, &h);
		game->position.img_ptr = game->img.img_ptr; // 플레이어 위치에 대한 이미지 포인터도 저장해줌
	}
}

void	draw_map(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '0') // '0'일 경우에 빈 공간이므로 pass
		{
			x++;
			continue ;
		}
		if (line[x] == 'P') // 'P'일 경우 플레이어
		{
			game->position.tile_x = x * TILES; // 플레이어의 x좌표 * 64
			game->position.tile_y = y * TILES; // 플레이어의 y좌표 * 64 (64픽셀로 그림 그리기 때문) -> 가장 오른쪽 하단 꼭짓점이 좌표가 됨
		}
		draw_pixels_of_tile(game, line[x]);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.img_ptr, x * TILES, y * TILES); // 해당 위치의 이미지 저장값을 출력
		i++;
	}
}
