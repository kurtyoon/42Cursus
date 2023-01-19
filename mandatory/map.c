/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:27:51 by cyun              #+#    #+#             */
/*   Updated: 2023/01/19 18:23:47 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_map_value(t_game *game, char component)
{
	if (component == '1' && !game->map_textures.wall)
		game->map_textures.wall = 1;
	else if (component == 'C')
		game->map_textures.collectible += 1;
	else if (component == 'P')
	{
		if (game->map_textures.player > 0)
			close_game_with_error(1);
		game->map_textures.player = 1;
	}
	else if (component == 'E')
	{
		if (game->map_textures.exit > 0)
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
	if (len != game->width)
		close_game_with_error(3);
	while (line[++i] && line[i] != '\n')
	{
		if ((i == 0 || i == len - 1) && line[i] != '1')
			close_game_with_error(4);
		if (check_wall && line[i] != '1')
			close_game_with_error(4);
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && \
				line[i] != 'C' && line[i] != 'E')
		{
			close_game_with_error(0);
		}
		set_map_value(game, line[i]);
	}
}

void	check_map_components(t_game *game)
{
	if (!game->map_textures.exit)
		close_game_with_error(5);
	if (!game->map_textures.player)
		close_game_with_error(5);
	if (!game->map_textures.collectible)
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
		line = get_next_line(fd);
		if (!line)
			break ;
		if (h == 0)
		{
			game->width = ft_strlen(line) - 1;
			check_map_line(game, line, check_wall);
		}
		else
			check_map_line(game, line, !check_wall);
		h += 1;
		free(line);
	}
	game->height = h;
	check_map_components(game);
}
