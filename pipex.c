/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:13:43 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:14:27 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ps_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
}

static void	child1(t_pipex *pip)
{
	dup2(pip->file1, 0);
	dup2(pip->fd[1], 1);
	close (pip->fd[0]);
	close (pip->fd[1]);
	close (pip->file1);
	close (pip->file2);
	execve(pip->cmd1[0], pip->cmd1, NULL);
	ps_error("Error: execve mistake");
	exit (127);
}

static void	child2(t_pipex *pip)
{
	dup2(pip->fd[0], 0);
	dup2(pip->file2, 1);
	close (pip->fd[0]);
	close (pip->fd[1]);
	close (pip->file1);
	close (pip->file2);
	execve(pip->cmd2[0], pip->cmd2, NULL);
	ps_error("Error: execve mistake");
	exit (127);
}

static void	make_cmd(t_pipex *pip)
{
	int	pid[2];
	int	status[2];

	pid[0] = fork();
	if (pid[0] == -1)
		ps_error("Error: fork mistake");
	if (pid[0] == 0)
		child1(pip);
	pid[1] = fork();
	if (pid[1] == -1)
		ps_error("Error: fork mistake");
	if (pid[1] == 0)
		child2(pip);
	close (pip->fd[0]);
	close (pip->fd[1]);
	close (pip->file1);
	close (pip->file2);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
}

int	main(int argc, char **argv, char **envr)
{
	t_pipex	*pip;

	pip = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pip)
		ps_error("Error: malloc error create struct");
	if (argc != 5)
		ps_error("Error: invalid number of parameters");
	pip->argv = argv;
	pipex_parsing(pip, envr);
	if (pipe(pip->fd) == -1)
		ps_error("Error: pipe mistake");
	make_cmd(pip);
	ft_free_split(pip->cmd1);
	ft_free_split(pip->cmd2);
	free(pip);
	return (0);
}
