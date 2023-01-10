/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:57 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 13:49:33 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// mlx를 init
void	init_minilibx(t_game *game)
{
	int	w;
	int	h;

	w = game->width; // 맵의 가로 입력
	h = game->height; // 맵의 세로 입력
	game->mlx_ptr = mlx_init(); // mlx 초기화
	game->win_ptr = mlx_new_window(game->mlx_ptr, w * TILES, \
	h * TILES, "[so_long]"); // mlx 윈도우 초기화, 이름은 so_long으로
}

// game 구조체를 초기화
void	init_param(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->map_textures.wall = 0;
	game->map_textures.player = 0;
	game->map_textures.collectible = 0;
	game->map_textures.exit = 0;
	game->collected = 0;
	game->move = 0;
	game->map = NULL;
	game->position.x = 0;
	game->position.y = 0;
	game->valid_path = 0;
}

void	get_map_line(t_game *game, char *line, int l)
{
	int		i;

	i = 0;
	game->map[l] = (char *)malloc(sizeof(char) * game->width); // 가로길이 만큼 동적 할당
	while (line[i])
	{
		if (line[i] == 'P') // 'P', 플레이어 라면
		{
			game->position.y = l;
			game->position.x = i;
			// game.position에 좌표 입력
		}
		game->map[l][i] = line[i]; // 맵 입력
		i++;
	}
}

// map의 마지막 줄을 체크
int	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1') // 마지막 줄이 벽이 아니라면 에러
		{
			close_game_with_error(4);
			return (0);
		}
		i++;
	}
	return (1);
}

void	init_map(t_game *game, int fd)
{
	int		i;
	int		is_valid;
	char	*line;

	i = 0;
	is_valid = 1;
	game->map = (char **)malloc(sizeof(char *) * game->height); // 맵을 입력하기 위해 동적 세로길이만큼 동적 할당
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		get_map_line(game, line, i); // 맵 입력
		if (i + 1 == game->height) // 마지막 줄이라면
			is_valid = check_last_line(line); // 마지막 줄 체크
		if (!is_valid) // 마지막 줄에 대한 타당성 검증
			close_game(game, 0);
		draw_map(game, line, i); // 맵 그리기
		free(line);
		i++;
	}
	check_path(game); // 맵에 가능한 경로 체크
	ft_putstr_fd("------------------\n", 1);
	ft_putstr_fd("   Game start !   \n", 1);
	ft_putstr_fd("------------------\n", 1);
}
