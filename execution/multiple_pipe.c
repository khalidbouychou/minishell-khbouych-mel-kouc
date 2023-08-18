/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:47:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/17 11:34:36 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	befor_exec(t_pipe *tmp, t_parse *lst_p)
{
	int		i;

	i = 0;
	close(tmp->prev->fd_p[1]);
	i = check_fd_exec(lst_p);
	close(tmp->fd_p[0]);
	close(tmp->prev->fd_p[1]);
	if (i != 1 && i != 3)
	{
		dup2(tmp->prev->fd_p[0], STDIN_FILENO);
		close(tmp->prev->fd_p[0]);
		if (i == 0)
		{
			dup2(tmp->fd_p[1], STDOUT_FILENO);
			close(tmp->fd_p[1]);
		}
	}
}

int	middle_pipes(t_pipe *tmp, t_parse *lst_p, t_env *env, char **str)
{
	lst_p->pid0 = fork();
	if (lst_p->pid0 == -1)
		return (-1);
	else if (lst_p->pid0 == 0)
	{
		befor_exec(tmp, lst_p);
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
	else
	{
		close(tmp->prev->fd_p[0]);
		close(tmp->prev->fd_p[1]);
	}
	return (1);
}

void	loop_cmd(t_pipe	*head, t_parse *lst_p, t_env *env, char **str)
{
	int		i;
	t_pipe	*tmp;

	i = 0;
	while (lst_p)
	{
		if (lst_p->next)
			tmp = creat_pipe(&head);
		if (i == 0)
			first_child(tmp->fd_p, lst_p, env, str);
		else if (lst_p->next)
			middle_pipes(tmp, lst_p, env, str);
		else if (!lst_p->next)
		{
			second_child(tmp->fd_p, lst_p, env, str);
			close(tmp->fd_p[0]);
			close(tmp->fd_p[1]);
		}
		close_fd(lst_p);
		lst_p = lst_p->next;
		i = 1;
	}
	free_pipe(head);
}

int	multiple_pipe(t_parse *lst_p, t_env *env, char **str, int size)
{
	t_pipe	*head;
	int		i;
	// int		status;

	i = 0;
	head = NULL;
	loop_cmd(head, lst_p, env, str);
	i = 0;
	while (i <= (size - 1))
	{
		// pid_t child_pid = waitpid(-1, &g_v.ex_stu, 0);
		waitpid(-1, &g_v.ex_stu, 0);
        // printf("GLOBAL = %d\n", g_v.ex_stu);
		// if (child_pid > 0)
		// {
        //     if (WIFEXITED(status))
		// 		printf("Child process %d (PID %d) exited with status: %d\n", i, child_pid, WEXITSTATUS(status));
		// 	else
		// 		printf("Child process %d (PID %d) terminated abnormally\n", i, child_pid);
		// }
		i++;
	}
	// while (waitpid(-1, NULL, 0) > 0);
	// waitpid(lst_p->pid0, &status, 0);
	return (1);
}
