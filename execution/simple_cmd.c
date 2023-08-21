/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/21 03:46:33 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	check_fd_exec(t_parse *list_pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (list_pars->fd_input != 0 && list_pars->fd_input != -1)
	{
		dup2(list_pars->fd_input, STDIN_FILENO);
		close(list_pars->fd_input);
		j++;
		i = 1;
	}
	if (list_pars->fd_output != 1 && list_pars->fd_output != -1)
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

void	fealed_s_n_exe(t_parse *list_pars)
{
	if (ft_strchr(list_pars->arg[0], '/') != -1)
		ft_fok_xok(list_pars);
	else
	{
		if ((!ft_strcmp(list_pars->arg[0], "") && list_pars->fd_input == 0)
			|| (access(list_pars->path, F_OK) == -1))
		{
			ft_putstr_fd("-->command not found\n", 2);
			exit(127);
		}
	}
	g_v.ex_stu = 0;
	exit(0);
}

void	child_simple(t_parse *list_pars, char **str)
{
	char	**cmd;

	cmd = NULL;
	if (ft_strchr(list_pars->arg[0], 32) != -1)
		cmd = ft_split(list_pars->arg[0], 32);
	check_fd_exec(list_pars);
	ft_defaultsig();
	if (g_v._flag == 1)
	{
		g_v._flag = 0;
		exit(0);
	}
	else
	{
		if (cmd)
		{
			if (execve(list_pars->path, cmd, str) == -1)
				fealed_s_n_exe(list_pars);
		}
		else if (execve(list_pars->path, list_pars->arg, str) == -1)
			fealed_s_n_exe(list_pars);
	}
	if (cmd)
		free_char_double(cmd);
}

int	simple_not_built(t_parse *list_pars, char **str)
{
	pid_t	id ;
	int		status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	id = fork();
	if (id == -1)
	{
		perror("error fork");
		exit(g_v.ex_stu = 1);
	}
	else if (id == 0)
	{
		ft_defaultsig();
		child_simple(list_pars, str);
	}
	close_fd(list_pars);
	waitpid(id, &status, 0);
	if (WIFEXITED(status))
		g_v.ex_stu = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit: 3", 2);
	ft_signals();
	return (1);
}
