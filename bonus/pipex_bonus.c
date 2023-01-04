/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:20:20 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:22:12 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ps_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
}

static void	pipex_add_init(t_pipex *pip)
{
	pip->fd = (int *)malloc(sizeof(int) * (pip->n_cmd - 1 + pip->l) * 2);
	if (!pip->fd)
		ps_error("Error: malloc error (init fd)");
	pip->pid = (int *)malloc(sizeof(int) * (pip->n_cmd + pip->l));
	if (!pip->pid)
		ps_error("Error: malloc error (init pid)");
	pip->status = (int *)malloc(sizeof(int) * (pip->n_cmd + pip->l));
	if (!pip->status)
		ps_error("Error: malloc error (init status)");
}

int	main(int argc, char **argv, char **envr)
{
	t_pipex	*pip;
	int		i;

	pip = pipex_parsing(argv, argc, envr);
	pipex_add_init(pip);
	parrent_process(pip);
	i = -1;
	while (++i < pip->n_cmd + pip->l)
		ft_free_split(pip->cmd[i]);
	free(pip->cmd);
	free(pip->fd);
	free(pip->pid);
	free(pip->status);
	free(pip);
	return (0);
}
