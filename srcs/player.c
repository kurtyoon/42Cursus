/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:44 by cyun              #+#    #+#             */
/*   Updated: 2023/01/09 16:01:03 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_move(t_game *game, int x, int y, int keycode)
{
	char	cur;

	cur = game->map[y][x]; // cur은 현재 위치
	if (keycode != KEY_W && keycode != KEY_S && \
	keycode != KEY_A && keycode != KEY_D)
		return (0); // 허용된 키가 아닌경우 0반환
	if (cur == '1')
		return (0); // 벽인 경우 0반환
	else if (cur == 'C') // 콜렉터블 인경우
	{
		game->collected += 1; // 콜렉터블 1증가
		game->map[y][x] = '0'; // 콜렉터블 위치 빈공간으로 변환
	}
	else if (cur == 'E') // 탈출구인 경우
	{
		if (game->collected == game->map_textures.collectible) // 전체 맵의 콜렉터블과 모은 콜렉터블이 같을경우
			close_game(game, 1); // 정상적으로 게임 종료
		else
			ft_putstr_fd("There's still a collectible left!\n", 1); // 아닐 경우 콜렉터블이 더 남았다는 메시지
	}
	return (1);
}

int	check_player_move(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	flag;

	flag = 1;
	x = game->position.x;
	y = game->position.y;
	if (keycode == KEY_W) // 'W'를 눌렀을 때 y 감소, 위로 올라가기
		y--;
	else if (keycode == KEY_S) // 'S'를 눌렀을 때 y 증가, 아래로 내려가기
		y++;
	else if (keycode == KEY_A) // 'A'를 눌렀을 때 x 감소, 왼쪽 방향
		x--;
	else if (keycode == KEY_D) // 'D'를 눌렀을 때 x 증가, 오른쪽 방향
		x++;
	else
		flag = 0;
	flag = check_valid_move(game, x, y, keycode);
	if (!flag)
		return (flag);
	if (game->map[game->position.y][game->position.x] == 'E')
		flag = 2;
	game->position.x = x;
	game->position.y = y;
	return (flag);
}

void	passing_exit(t_game *game, int prev_x, int prev_y)
{
	draw_pixels_of_tile(game, 'E');
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.img_ptr, prev_x, prev_y);
}

void	draw_updated_player(t_game *game, int prev_x, int prev_y)
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
			game->img.data[h * TILES + w] = 0x000000;
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

	if (keycode == KEY_ESC) //'ESC'를 눌렀을 때 게임 종료
		close_game(game, 1);
	flag = check_player_move(keycode, game);
	if (flag)
	{
		prev_x = game->position.tile_x;
		prev_y = game->position.tile_y;
		if (keycode == KEY_W)
			game->position.tile_y -= TILES;
		else if (keycode == KEY_S)
			game->position.tile_y += TILES;
		else if (keycode == KEY_A)
			game->position.tile_x -= TILES;
		else if (keycode == KEY_D)
			game->position.tile_x += TILES;
		draw_updated_player(game, prev_x, prev_y);
		if (flag == 2)
			passing_exit(game, prev_x, prev_y);
		print_move(game->move);
	}
	return (0);
}
