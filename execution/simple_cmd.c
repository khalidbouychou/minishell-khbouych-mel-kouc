/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/08 23:08:41 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	check_fd_exec(t_parse *list_pars)
{
	int	i;

	i = 0;
	if (list_pars->fd_input != 0)
	{
		dup2(list_pars->fd_input, STDIN_FILENO);
		close(list_pars->fd_input);
		i = 1;
	}
	if (list_pars->fd_output != 1)
	{
		dup2(list_pars->fd_output, STDOUT_FILENO);
		close(list_pars->fd_output);
		i = 2;
	}
	return (i);
}


int	simple_not_built(t_parse *list_pars, t_env *env, char **str)
{
	pid_t	id ;
	int		status;

	id = fork();
	if (id == -1)
		return (-1);
	// if (id == -1)
	// {
    //     perror("open");
    //     exit(g_stu.ex_stu = 0);
    // }
	else if (id == 0)
	{
		check_fd_exec(list_pars);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);

		// printf("g_stu.flag = %d\n", g_stu.flag);
		// if (g_stu.flag == 1)
		// {
		// 	printf("hhhhhh");
		// 	g_stu.flag = 0;
		// 	exit(0);
		// }
		// else
		// {
			if (execve(list_pars->path, list_pars->arg, str) == -1)
			{
				// if (fealed_execve(list_pars))
				fealed_execve(list_pars);
				// else 
				// exit(g_stu.ex_stu = 127);
			}
		// }
	}	
	// printf("g_stu.ex_stu = %d\n",g_stu.ex_stu);
	waitpid(id, &status, 0);
	if (WIFEXITED(status))
	{
		g_stu.ex_stu = WEXITSTATUS(status);
        printf("Child exited with status: %d\n", g_stu.ex_stu);
    } else if (WIFSIGNALED(status))
	{
        if(WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit: 3",2);
    }
	// if (status == 256)
	// 	g_stu.ex_stu = 1;
	// else if (status == 0)
	// {
	// 	// printf("xit %d\n", g_stu.ex_stu);
	// 	g_stu.ex_stu = 0;
	// }
	// printf("status = %d\n", status);
	// printf("id  = %d\n", id);
	(void)env;
	return (1);
}
