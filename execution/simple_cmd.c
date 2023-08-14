/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/12 11:50:53 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	check_fd_exec(t_parse *list_pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (list_pars->fd_input != 0)
	{
		dup2(list_pars->fd_input, STDIN_FILENO);
		close(list_pars->fd_input);
		j++;
		i = 1;
	}
	if (list_pars->fd_output != 1)
	{
		j = j + 2;
		dup2(list_pars->fd_output, STDOUT_FILENO);
		close(list_pars->fd_output);
		i = 2;
	}
	if (j == 3)
		return (j);
	return (i);
}

int	simple_not_built(t_parse *list_pars, char **str)
{
	pid_t	id ;
	int		status;

	id = fork();
	if (id == -1)
	{
		perror("open");
		exit(g_stu.ex_stu = 1);
	}
	else if (id == 0)
	{
		check_fd_exec(list_pars);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (execve(list_pars->path, list_pars->arg, str) == -1)
			fealed_execve(list_pars);
	}
	close_fd(list_pars);
	waitpid(id, &status, 0);
	if (WIFEXITED(status))
		g_stu.ex_stu = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit: 3", 2);
	return (1);
}
