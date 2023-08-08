/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/07 14:53:05 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	check_fd_exec(t_parse *list_pars)
{
	if (list_pars->fd_input != 0)
	{
		dup2(list_pars->fd_input, STDIN_FILENO);
		close(list_pars->fd_input);
	}
	if (list_pars->fd_output != 1)
	{
		dup2(list_pars->fd_output, STDOUT_FILENO);
		close(list_pars->fd_output);
	}
}

int	simple_not_built(t_parse *list_pars, t_env *env, char **str)
{
	pid_t	id ;
	int		status;

	id = fork();
	if (id == -1)
		return (-1);
	else if (id == 0)
	{
		check_fd_exec(list_pars);
		if (execve(list_pars->path, list_pars->arg, str) == -1)
			fealed_execve(list_pars);
	}
	waitpid(id, &status, 0);
	if (status == 256)
		g_stu.ex_stu = 1;
	else if (status == 0)
		g_stu.ex_stu = 0;
	// printf("status = %d\n", status);
	// printf("id  = %d\n", id);
	(void)env;
	return (1);
}
