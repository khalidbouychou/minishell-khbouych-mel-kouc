/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:44:27 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/24 13:28:37 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

pid_t	pid_second_child(t_pipe *tmp, t_parse *lst_p, t_env *env, char **str)
{
	pid_t	pid;

	pid = second_child(tmp->fd_p, lst_p, env, str);
	close(tmp->fd_p[0]);
	close(tmp->fd_p[1]);
	return (pid);
}

void	wait_id(pid_t pid[], int *status)
{
	waitpid(pid[0], status, 0);
	waitpid(pid[1], status, 0);
	waitpid(pid[2], status, 0);
	ftstatus(status);
}

void	cmd_in_built(t_parse *list_pars, t_env **env, int pipe)
{
	t_parse	*tmp;

	tmp = list_pars;
	ft_tolower(*tmp->arg);
	if (!ft_strcmp(tmp->arg[0], "echo"))
		ft_echo(tmp->arg, tmp->fd_output);
	else if (!ft_strcmp(tmp->arg[0], "env"))
		ft_env(tmp, env);
	else if (!ft_strcmp(tmp->arg[0], "export"))
		ft_export(tmp->arg, *env, tmp->fd_output);
	else if (!ft_strcmp(tmp->arg[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(tmp->arg[0], "exit"))
		ft_exit(tmp->arg, pipe);
	else if (!ft_strcmp(tmp->arg[0], "unset"))
		ft_unset(env, tmp->arg);
	else if (!ft_strcmp(tmp->arg[0], "cd"))
		ft_cd(tmp->arg, *env);
	if (tmp->fd_input == -1)
		g_v.ex_stu = 1;
}

void	execute_main(t_parse *list_pars, t_env **env)
{
	char	**str;

	str = NULL;
	str = list_to_char(*env, str);
	if (list_pars && !list_pars->next)
	{
		if (compare_cmd(list_pars))
		{
			cmd_in_built(list_pars, env, 0);
			close_fd(list_pars);
		}
		else if (g_v._flag == 1)
			g_v._flag = 0;
		else
			simple_not_built(list_pars, str);
	}
	else
		complex_cmd(list_pars, *env, str);
	close_fd(list_pars);
	free_char_double(str);
}
