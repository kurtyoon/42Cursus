/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:51 by cyun              #+#    #+#             */
/*   Updated: 2023/01/09 15:42:17 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_map_value(t_game *game, char component)
{
	if (component == '1' && !game->map_textures.wall) // '1'이고 map_textures에 wall이 없는 경우
		game->map_textures.wall = 1;
	else if (component == 'C') // 'C'인 경우 콜렉터블 1증가
		game->map_textures.collectible += 1;
	else if (component == 'P') // 'P'인 경우
	{
		if (game->map_textures.player > 0) // 플레이어가 존재한다면 에러
			close_game_with_error(1);
		game->map_textures.player = 1;
	}
	else if (component == 'E') // 'E' 인경우
	{
		if (game->map_textures.exit > 0) // 출구가 존재한다면 에러
			close_game_with_error(2);
		game->map_textures.exit = 1;
	}
}

void	check_map_line(t_game *game, char *line, int check_wall)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line) - 1;
	if (len != game->width) // 읽어온 길이와 가로길이가 다를경우
		close_game_with_error(3);
	while (line[++i] && line[i] != '\n') // 개행문자 전까지
	{
		if ((i == 0 || i == len - 1) && line[i] != '1') // 양 끝이 벽이 아닐경우
			close_game_with_error(4);
		if (check_wall && line[i] != '1') // 첫 번째 줄이 벽이 아닌경우
			close_game_with_error(4);
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && \
				line[i] != 'C' && line[i] != 'E')
		{
			close_game_with_error(0); // 다른 문자가 있는 경우
		}
		set_map_value(game, line[i]); // game 구조체에 맵 입력
	}
}

void	check_map_components(t_game *game)
{
	if (!game->map_textures.exit) // 출구가 없다면
		close_game_with_error(5);
	if (!game->map_textures.player) // 플레이어가 없다면
		close_game_with_error(5);
	if (!game->map_textures.collectible) // 콜렉터블이 없다면
		close_game_with_error(5);
}

void	get_map(t_game *game, int fd)
{
	char	*line;
	int		h;
	int		check_wall;

	h = 0;
	check_wall = 1;
	while (1)
	{
		// 파일을 한 줄 씩 읽어오기
		line = get_next_line(fd);
		if (!line)
			break ;
		if (h == 0) // 첫 번째 줄일경우
		{
			game->width = ft_strlen(line) - 1; // 가로길이 입력
			check_map_line(game, line, check_wall); // 해당 줄 유효성 검증, 모두 벽이어야함
		}
		else // 아닐 경우
			check_map_line(game, line, !check_wall); // 해당 줄 유효성 검증
		h += 1;
		free(line); // 다음을 위해 free
	}
	game->height = h; // 최종적으로 세로길이 입력
	check_map_components(game); // 맵의 요소에 대한 유효성 검증
}
