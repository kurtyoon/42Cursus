/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:44 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 13:47:25 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_valid_move(t_game *game, int y, int x, int keycode)
{
	char	cur;

	cur = game->map[y][x]; // cur은 플레이여의 현재 위치
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
	return (1); // 빈공간이거나 콜렉터블이거나 콜렉터블이 남았을 때 출구라면 1 반환
}

int	check_player_move(int keycode, t_game *game)
{
	int	nx;
	int	ny;
	int	flag;

	flag = 1;
	ny = game->position.y; // 플레이어의 y좌표
	nx = game->position.x; // 플레이어의 x좌표
	if (keycode == KEY_W) // 'W'를 눌렀을 때 y 감소, 위로 올라가기
		ny--;
	else if (keycode == KEY_S) // 'S'를 눌렀을 때 y 증가, 아래로 내려가기
		ny++;
	else if (keycode == KEY_A) // 'A'를 눌렀을 때 x 감소, 왼쪽 방향
		nx--;
	else if (keycode == KEY_D) // 'D'를 눌렀을 때 x 증가, 오른쪽 방향
		nx++;
	else // 아닐경우 flag = 0
		flag = 0;
	flag = check_valid_move(game, ny, nx, keycode); // 빈공간이거나 콜렉터블이거나 콜렉터블이 남았을 때 출구라면 1 반환
	if (!flag) // 잘못된 경우라면 해당 플레그 반환
		return (flag);
	if (game->map[game->position.y][game->position.x] == 'E')
		flag = 2;
	game->position.y = ny; // 플레이어의 y좌표 업데이트
	game->position.x = nx; // 플레이어의 x좌표 업데이트
	return (flag); // 출구라면 2반환, 뭔가 남았는데 올바른 경우 1반환
}

void	passing_exit(t_game *game, int prev_y, int prev_x)
{
	draw_pixels_of_tile(game, 'E'); // 출구에 대한 이미지 업데이트
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
	while (h < TILES) // 원래 있던 플레이어의 공간의 데이터를 빈 공간으로 교체
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
	game->position.img_ptr, prev_x, prev_y); // 데이터에 맞게 빈 공간으로 그리기
	draw_pixels_of_tile(game, 'P'); // 플레이어에 대한 이미지 업데이트
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->position.img_ptr, game->position.tile_x, game->position.tile_y); // 새롭게 움직인 위치에 대한 플레이어의 그림 업데이트
	game->move += 1; // 움직인 횟수 증가
}

int	press_key(int keycode, t_game *game)
{
	int	prev_x;
	int	prev_y;
	int	flag;

	if (keycode == KEY_ESC) //'ESC'를 눌렀을 때 게임 종료
		close_game(game, 1);
	flag = check_player_move(keycode, game); // 끝나면 2반환, 뭔가 남았는데 올바른 경우 1반환
	if (flag)
	{
		prev_y = game->position.tile_y; // 플레이어의 이전 픽셀 y좌표를 가져옴
		prev_x = game->position.tile_x; // 플레이어의 이전 픽셀 x좌표를 가져옴
		if (keycode == KEY_W) // W를 눌렀을 떄
			game->position.tile_y -= TILES; // y--이므로 64만큼 감소
		else if (keycode == KEY_S) // S를 눌렀을 때
			game->position.tile_y += TILES; // y++이므로 64만큼 증가
		else if (keycode == KEY_A) // A를 눌렀을 때
			game->position.tile_x -= TILES; // x--이므로 64만큼 감소
		else if (keycode == KEY_D) // D를 눌렀을 때
			game->position.tile_x += TILES; // x++이므로 64만큼 증가
		draw_update_player(game, prev_y, prev_x); // 플레이어의 그림 업데이트
		if (flag == 2) // 플레그가 2일경우 출구로 이동
			passing_exit(game, prev_y, prev_x);
		print_move(game->move); // 움직임 업데이트
	}
	return (0);
}
