/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:05:58 by cyun              #+#    #+#             */
/*   Updated: 2023/01/10 12:49:17 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 정상적으로 게임이 끝났을 때 프로그램 종료 함수
int	close_game(t_game *game, int type)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
	free(game->mlx_ptr);
	if (type)
	{
		ft_putstr_fd("------------------\n", 1);
		ft_putstr_fd(" The Game Is Over \n", 1);
		ft_putstr_fd("------------------\n", 1);
	}
	exit(0);
}

// 에러 메시지 출력 함수
int	close_game_with_error(int type)
{
	ft_putstr_fd("[Error]\n", 1);
	if (type == 0)
	{
		ft_putstr_fd("The map must be composed of only ", 1);
		ft_putstr_fd("5 possible characters(0, 1, C, E, P) !\n", 1);
	}
	else if (type == 1)
		ft_putstr_fd("There must be only one player !\n", 1);
	else if (type == 2)
		ft_putstr_fd("Theere must be only one exit !\n", 1);
	else if (type == 3)
		ft_putstr_fd("The map must be rectangular !\n", 1);
	else if (type == 4)
		ft_putstr_fd("The map must be closed or surrounded by walls !\n", 1);
	else if (type == 5)
	{
		ft_putstr_fd("Map must have at least one exit, one collectible, ", 1);
		ft_putstr_fd("and one starting position !\n", 1);
	}
	else if (type == 6)
		ft_putstr_fd("The map must have valid path !\n", 1);
	else if (type == -1)
		ft_putstr_fd("The files does not exist !", 1);
	exit(1);
}

// 몇 번 움직였는지 출력하는 함수
void	print_move(char c)
{
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	game;

	if (argc != 2) // 인자가 잘못 됐을 때
	{
		ft_putstr_fd("[Error]\n", 1);
		ft_putstr_fd("Try './so_long [Map_name.ber]'\n", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY); // 맵 열기
	if (fd == -1)
		close_game_with_error(-1);
	init_param(&game); // 구조체 초기화
	get_map(&game, fd); // 맵의 요소 입력
	init_minilibx(&game); // mlx를 위한 초기화
	close(fd);
	fd = open(argv[1], O_RDONLY); // 맵을 새로 읽어 오기 위해서 한번 더 open
	if (fd == -1)
		close_game_with_error(-1);
	init_map(&game, fd); // 맵 입력후 유효성 검증 및 초기 맵 그리기
	close(fd);
	mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &game); // 플레이어 움직임에 따라 맵 그리기
	mlx_hook(game.win_ptr, X_EVENT_EXIT, 0, &close_game, &game); // 게임 종료
	mlx_loop(game.mlx_ptr);
	return (0);
}
