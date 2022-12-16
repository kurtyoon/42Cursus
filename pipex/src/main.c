/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:56:57 by cyun              #+#    #+#             */
/*   Updated: 2022/11/12 22:35:24 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	find_command(t_pipexdata *data, char *cmd, char **full_path)
{
	char	*tmp;
	int		i;

	i = -1;
	*full_path = NULL;
	while (data->env_path && data->env_path[++i])
	{
		free(*full_path);
		tmp = ft_strjoin(data->env_path[i], "/");
		if (!tmp)
			return (-2);
		*full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return (-2);
		if (access(*full_path, F_OK) == 0)
			break ;
	}
	if (!data->env_path || !data->env_path[i])
	{
		free(*full_path);
		return (-1);
	}
	return (0);
}

t_list	*parse_commands(int argc, char **argv, t_pipexdata *data)
{
	int		i;
	char	*full_path;
	char	**cmd;
	t_list	*cmds;
	int		tmp;

	cmds = NULL;
	i = 1;
	full_path = NULL;
	while (++i < argc -1)
	{
		data->cmds = cmds;
		cmd = ft_split(argv[i], ' ');
		if (!cmd || !*cmd)
			return ((t_list *)pipex_exit(data, NULL, CMD_NOT_FOUND, &cmd));
		tmp = find_command(data, *cmd, &full_path);
		if (!*cmd || tmp == -1)
			return (pipex_exit(data, *cmd, CMD_NOT_FOUND, &cmd));
		if (tmp == -2)
			return (pipex_exit(data, NULL, NO_MEMORY, &cmd));
		ft_lstadd_back(&cmds, pipex_lstnew(full_path, cmd));
		free(full_path);
	}
	return (cmds);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipexdata	*d;

	if (argc != 5)
		return (*(int *)pipex_exit(NULL, NULL, INV_ARGS, NULL));
	if (access(argv[1], F_OK) == -1)
		return (*(int *)pipex_exit(NULL, argv[1], NO_FILE, NULL));
	if (access(argv[1], R_OK) == -1)
		return (*(int *)pipex_exit(NULL, argv[1], NO_PERM, NULL));
	d = pipex_get_data(argc, argv, 0, envp);
	d->cmds = parse_commands(argc, argv, d);
	pipex(d, envp);
	return (*(int *)pipex_exit(d, NULL, 1, NULL));
}
