/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:23:15 by cyun              #+#    #+#             */
/*   Updated: 2022/11/12 22:29:40 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_pipexdata	*pipex_get_data(int argc, char **argv, int here_doc, char **envp)
{
	t_pipexdata	*data;
	int			i;

	i = 0;
	data = malloc(sizeof(struct s_pipexdata));
	if (!data)
		return ((t_pipexdata *)pipex_exit(data, NULL, NO_MEMORY, NULL));
	data->env_path = NULL;
	data->cmds = NULL;
	data->in_fd = open(argv[1], O_RDONLY);
	if (data->in_fd == -1)
		return ((t_pipexdata *)pipex_exit(data, argv[1], NO_FILE, NULL));
	if (!here_doc)
		data->out_fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (access(argv[argc - 1], F_OK) == -1)
		return ((t_pipexdata *)pipex_exit(data, argv[argc - 1], NO_FILE, NULL));
	if (access(argv[argc - 1], W_OK) == -1)
		return ((t_pipexdata *)pipex_exit(data, argv[argc - 1], NO_PERM, NULL));
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	data->env_path = ft_split(envp[i], ':');
	if (!data->env_path)
		return ((t_pipexdata *)pipex_exit(data, NULL, NO_PATH, NULL));
	return (data);
}

void	*pipex_child(t_pipexdata *data, int fd[2], t_list *start, char **envp)
{
	t_pipexcmd	*cmd;

	cmd = start->content;
	close(fd[READ_END]);
	if (start->next && dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		return (pipex_exit(data, NULL, DUP_ERR, NULL));
	if (!start->next && dup2(data->out_fd, STDOUT_FILENO) == -1)
		return (pipex_exit(data, NULL, DUP_ERR, NULL));
	close(fd[WRITE_END]);
	close(data->in_fd);
	close(data->out_fd);
	execve(cmd->full_path, cmd->cmd, envp);
	return (pipex_exit(data, NULL, CMD_FAIL, NULL));
}

void	pipex_perror(char *param, int err)
{
	ft_putstr_fd("pipex: ", 2);
	if (err == CMD_NOT_FOUND)
		ft_putstr_fd("command not found: ", 2);
	if (err == NO_FILE)
		ft_putstr_fd("no such file or directory: ", 2);
	if (err == NO_PERM)
		ft_putstr_fd("permission denied: ", 2);
	if (err == CMD_FAIL)
		ft_putstr_fd("command failed: ", 2);
	if (err == INV_ARGS)
		ft_putstr_fd("invalid number of arguments", 2);
	if (err == NO_MEMORY)
		ft_putstr_fd("no memory left on device", 2);
	if (err == DUP_ERR)
		ft_putstr_fd("could not dup fd", 2);
	if (err == PIPE_ERR)
		ft_putstr_fd("could not create pipe", 2);
	if (err == FORK_ERR)
		ft_putstr_fd("could not fork process", 2);
	if (err == NO_PATH)
		ft_putstr_fd("PATH variable is not set", 2);
	if (param && (err == CMD_NOT_FOUND || err == NO_FILE \
			|| err == NO_PERM || err == CMD_FAIL))
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
}

void	*pipex(t_pipexdata *d, char **envp)
{
	int			fd[2];
	pid_t		pid;
	t_list		*start;

	start = d->cmds;
	if (dup2(d->in_fd, STDIN_FILENO) == -1)
		return (pipex_exit(d, NULL, DUP_ERR, NULL));
	close(d->in_fd);
	while (start)
	{
		if (pipe(fd) == -1)
			return (pipex_exit(d, NULL, PIPE_ERR, NULL));
		pid = fork();
		if (pid == -1)
			return (pipex_exit(d, NULL, FORK_ERR, NULL));
		if (!pid)
			pipex_child(d, fd, start, envp);
		close(fd[WRITE_END]);
		if (start->next && dup2(fd[READ_END], STDIN_FILENO) == -1)
			return (pipex_exit(d, NULL, DUP_ERR, NULL));
		waitpid(pid, NULL, 0);
		close(fd[READ_END]);
		start = start->next;
	}
	return (NULL);
}
