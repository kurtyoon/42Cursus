/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:40:23 by cyun              #+#    #+#             */
/*   Updated: 2023/01/09 14:25:26 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_visited(int **visited)
{
	int	i;

	i = -1;
	while (visited[++i])
	{
		free(visited[i]);
		visited[i] = 0;
	}
	free(visited);
	visited = 0;
}

int	**visited_init(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	i = -1;
	visited = (int **)malloc(sizeof(int *) * game->height);
	if (!visited)
		return(0);
	while (++i < game->height - 1)
	{
		visited[i] = (int *)malloc(sizeof(int) * (game->width + 1));
		if (!visited[i])
		{
			free_visited(visited);
			return (0);
		}
		j = -1;
		while (j < game->width)
			visited[i][++j] = 0;
	}
	visited[i] = 0;
	return (visited);
}

void	dfs(t_game *game, t_check *check, int y, int x)
{
	const int	dy[4] = {1, -1, 0, 0};
	const int	dx[4] = {0, 0, 1, -1};
	int			ny;
	int			nx;
	int			i;

	check->visited[y][x] = 1;
	i = -1;
	if (game->map[y][x] == 'C')
		check->collectible -= 1;
	if (game->map[y][x] == 'E')
	{
		game->valid_path = 1;
		return ;
	}
	while (++i < 4)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (game->map[ny][nx] != '1' && !check->visited[ny][nx])
			dfs(game, check, ny, nx);
	}

}

void	init_check(t_game *game, t_check *check)
{
	check->visited = visited_init(game);
	check->y = game->height;
	check->x = game->width;
	check->collectible = game->map_textures.collectible;
}

void	check_path(t_game *game)
{
	t_check	check;

	init_check(game, &check);
	dfs(game, &check, game->position.y, game->position.x);
	if (!game->valid_path || check.collectible > 0)
		close_game_with_error(6);
	free_visited(check.visited);
}
