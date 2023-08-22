/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:50:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/22 00:59:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	execut_in_child(t_parse *lst_p, t_env *env, char **str)
{
	if (compare_cmd(lst_p))
	{
		lst_p->fd_output = 1;
		cmd_in_built(lst_p, &env);
		exit(g_v.ex_stu);
	}
	else if (execve(lst_p->path, lst_p->arg, str) == -1)
	{
		fealed_execve(lst_p);
		exit(g_v.ex_stu);
	}
}

int	second_child(int fd[2], t_parse *lst_p, t_env *env, char **str)
{
	// ft_defaultsig();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (lst_p->fd_output == -1 || lst_p->fd_input == -1)
		return (1);
	lst_p->pid0 = fork();
	if (lst_p->pid0 == -1)
		return (-1);
	else if (lst_p->pid0 == 0)
	{
		// ft_defaultsig();
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(fd[1]);
		if (check_fd_exec(lst_p) != 1 && check_fd_exec(lst_p) != 3)
			dup2(fd[0], STDIN_FILENO);
		if (lst_p->fd_output == 1 && lst_p->fd_input == -1)
			dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
		execut_in_child(lst_p, env, str);
	}
	return (1);
}

int	first_child(int fd[2], t_parse *lst_p, t_env *env, char **str)
{
	// ft_defaultsig();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (lst_p->fd_output == -1 || lst_p->fd_input == -1)
		return (1);
	lst_p->pid0 = fork();
	if (lst_p->pid0 == -1)
		return (-1);
	else if (lst_p->pid0 == 0)
	{
		// ft_defaultsig();
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(fd[0]);
		if (check_fd_exec(lst_p) == 0)
			dup2(fd[1], STDOUT_FILENO);
		if (lst_p->fd_output == 1)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execut_in_child(lst_p, env, str);
	}
	return (1);
}

int	one_pipe(t_parse *lst_p, t_env *env, char **str)
{
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	if (first_child(fd, lst_p, env, str) == -1)
		return (-1);
	if (second_child(fd, lst_p->next, env, str) == -1)
		return (-1);
	close_fd(lst_p);
	close_fd(lst_p->next);
	close(fd[0]);
	close(fd[1]);
	waitpid(lst_p->pid0, &status, 0);
	waitpid(lst_p->next->pid0, &status, 0);
	ft_signals();
	if (status == 256)
		g_v.ex_stu = 1;
	else if (status == 0)
		g_v.ex_stu = 0;
	return (1);
}
