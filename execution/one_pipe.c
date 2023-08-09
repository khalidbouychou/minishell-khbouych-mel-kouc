/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:50:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/08 16:49:46 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	second_child(int fd[2], t_parse *lst_p, t_env *env, char **str)
{
	lst_p->pid0 = fork();
	if (lst_p->pid0 == -1)
		return (-1);
	else if (lst_p->pid0 == 0)
	{
		close(fd[1]);
		if (check_fd_exec(lst_p) != 1)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (compare_cmd(lst_p))
		{
			lst_p->fd_output = 1;
			cmd_in_built(lst_p, &env);
			exit(g_stu.ex_stu);
		}
		else
			execve(lst_p->path, lst_p->arg, str);
	}
	return (1);
}

int	first_child(int fd[2], t_parse *lst_p, t_env *env, char **str)
{
	lst_p->pid0 = fork();
	if (lst_p->pid0 == -1)
		return (-1);
	else if (lst_p->pid0 == 0)
	{
		close(fd[0]);
		if (check_fd_exec(lst_p) == 0)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (compare_cmd(lst_p))
		{
			lst_p->fd_output = 1;
			cmd_in_built(lst_p, &env);
			exit(g_stu.ex_stu);
		}
		else
			execve(lst_p->path, lst_p->arg, str);
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
	first_child(fd, lst_p, env, str);
	second_child(fd, lst_p->next, env, str);
	close(fd[0]);
	close(fd[1]);
	waitpid(lst_p->pid0, &status, 0);
	waitpid(lst_p->next->pid0, &status, 0);
	if (status == 256)
		g_stu.ex_stu = 1;
	else if (status == 0)
		g_stu.ex_stu = 0;
	return (1);
}


// int	second_child(int fd[2], t_parse *lst_p, t_env *env, char **str)
// {
// 	pid_t	pid1;

// 	// (void)env;
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return (-1);
// 	else if (pid1 == 0)
// 	{
// 		close(fd[1]);
// 		if (check_fd_exec(lst_p) != 1)
// 			dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		if (compare_cmd(lst_p))
// 		{
// 			lst_p->fd_output = 1;
// 			cmd_in_built(lst_p, &env);
// 			exit(g_stu.ex_stu);
// 		}
// 		else
// 			execve(lst_p->path, lst_p->arg, str);
// 	}
// 	return (pid1);
// }

// int	first_child(int fd[2], t_parse *lst_p, t_env *env, char **str)
// {
// 	pid_t	pid0;

// 	pid0 = fork();
// 	if (pid0 == -1)
// 		return (-1);
// 	else if (pid0 == 0)
// 	{
// 		close(fd[0]);
// 		if (check_fd_exec(lst_p) == 0)
// 			dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 		if (compare_cmd(lst_p))
// 		{
// 			lst_p->fd_output = 1;
// 			cmd_in_built(lst_p, &env);
// 			exit(g_stu.ex_stu);
// 		}
// 		else
// 			execve(lst_p->path, lst_p->arg, str);
// 	}
// 	return (pid0);
// }

// int	one_pipe(t_parse *lst_p, t_env *env, char **str)
// {
// 	pid_t	pid0;
// 	pid_t	pid1;
// 	int		fd[2];
// 	int		status;

// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		return (-1);
// 	}
// 	pid0 = first_child(fd, lst_p, env, str);
// 	pid1 = second_child(fd, lst_p->next, env, str);
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid0, &status, 0);
// 	waitpid(pid1, &status, 0);
// 	if (status == 256)
// 		g_stu.ex_stu = 1;
// 	else if (status == 0)
// 		g_stu.ex_stu = 0;
// 	return (1);
// }
