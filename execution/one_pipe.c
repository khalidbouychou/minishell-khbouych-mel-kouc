/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:50:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/03 22:00:17 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

// int	second_child(pid_t	*pid1, t_parse *lst_p, t_env *env, char **str)
// {
// 	*pid1 = fork();
// 	if (*pid1 == -1)
// 		return (-1);
// 	else if (*pid1 == 0)
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		if (compare_cmd(lst_p->next))
// 		{
// 			cmd_in_built(lst_p->next, &env);
// 			exit(g_stu.ex_stu);
// 		}
// 		else
// 			execve(lst_p->next->path, lst_p->next->arg, str);
// 	}
// 	retutn (1);
// }

// int	first_child(pid_t	*pid0, t_parse *lst_p, t_env *env, char **str)
// {
// 	*pid0 = fork();
// 	if (*pid0 == -1)
// 		return (-1);
// 	else if (*pid0 == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 		if (compare_cmd(lst_p))
// 		{
// 			cmd_in_built(lst_p, &env);
// 			exit(g_stu.ex_stu);
// 		}
// 		else
// 			execve(lst_p->path, lst_p->arg, str);
// 	}
// 	retutn (1);
// }

int	one_pipe(t_parse *lst_p, t_env *env, char **str)
{
	pid_t	pid0;
	pid_t	pid1;
	int		fd[2];
	int		status;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	// first_child(&pid0, lst_p, env, str);
	// second_child(&pid1, lst_p, env, str);
	pid0 = fork();
	if (pid0 == -1)
		return (-1);
	else if (pid0 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		check_fd_exec(lst_p);
		if (compare_cmd(lst_p))
		{
			cmd_in_built(lst_p, &env);
			exit(g_stu.ex_stu);
		}
		else
			execve(lst_p->path, lst_p->arg, str);
	}
	pid1 = fork();
	if (pid1 == -1)
		return (-1);
	else if (pid1 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		check_fd_exec(lst_p->next);
		if (compare_cmd(lst_p->next))
		{
			cmd_in_built(lst_p->next, &env);
			exit(g_stu.ex_stu);
		}
		else
			execve(lst_p->next->path, lst_p->next->arg, str);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid0, &status, 0);
	waitpid(pid1, &status, 0);
	if (status == 256)
		g_stu.ex_stu = 1;
	else if (status == 0)
		g_stu.ex_stu = 0;
	return (1);
}
