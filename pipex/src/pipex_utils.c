/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:11:06 by cyun              #+#    #+#             */
/*   Updated: 2022/11/15 13:33:02 by cyun             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static t_pipexcmd	*pipex_newcmd(char *full_path, char **cmd)
{
	t_pipexcmd	*newcmd;

	if (!cmd)
		return (NULL);
	newcmd = malloc(sizeof(t_pipexcmd));
	if (!newcmd)
		return (NULL);
	newcmd->full_path = ft_strdup(full_path);
	if (full_path && !newcmd->full_path)
	{
		free(newcmd);
		return (NULL);
	}
	newcmd->cmd = cmd;
	return (newcmd);
}

t_list	*pipex_lstnew(char *full_path, char **cmd)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = pipex_newcmd(full_path, cmd);
	if (!newnode->content)
	{
		free(newnode);
		return (NULL);
	}
	newnode->next = NULL;
	return (newnode);
}

void	pipex_freecmd(void *node)
{
	t_pipexcmd	*tmp;

	tmp = (struct s_pipexcmd *)node;
	free(tmp->full_path);
	ft_free_matrix(&tmp->cmd);
	free(tmp);
}

void	*pipex_exit(t_pipexdata *data, char *param, int err, char ***cmd)
{
	if (err < 1 || param)
		pipex_perror(param, err);
	if (cmd)
		ft_free_matrix(cmd);
	if (data)
	{
		close(STDIN_FILENO);
		close(data->in_fd);
		close(data->out_fd);
		if (data->cmds)
			ft_lstclear(&data->cmds, pipex_freecmd);
		if (data->env_path)
			ft_free_matrix(&data->env_path);
		free(data);
	}
	exit(0);
	return (0);
}

// memory free about matrix
void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	free(m[0]);
	m = NULL;
}
