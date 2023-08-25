/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:45 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/25 23:01:22 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	exit_fd_close(int pipe)
{
	if (pipe == 1)
	{
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
}

void	ft_exit_output(char *msg, int exit_status, bool _bool)
{
	ft_putstr_fd(msg, 2);
	if (_bool)
		exit(g_v.ex_stu = exit_status);
	else
		g_v.ex_stu = exit_status;
}

void	ft_exit(char **arg, int pipe)
{
	int	stdout_backup;

	stdout_backup = dup(STDERR_FILENO);
	exit_fd_close(pipe);
	if (!ft_strcmp(arg[0], "exit") && arg[1] == NULL)
		ft_exit_output("exit\n", 0, true);
	else if (!ft_arg_digit(arg[1]) || (arg[1] && ft_strlen(arg[1])
			> ft_strlen("-9223372036854775808"))
		|| (ft_atoi(arg[1]) < 0 && arg[1][0] != '-')
		|| (ft_atoi(arg[1]) > 0 && arg[1][0] == '-') || !ft_strcmp(arg[1], ""))
	{
		dup2(stdout_backup, STDERR_FILENO);
		ft_exit_output("exit : numeric argument required\n", 255, true);
	}
	else if (arg[2])
	{
		dup2(stdout_backup, STDERR_FILENO);
		ft_exit_output("exit : too many arguments\n", 1, false);
	}
	else if (ft_arg_digit(arg[1]) && arg[2] == NULL)
		ft_exit_output("exit\n", ft_atoi((arg[1])), true);
	else if (ft_isdigit(arg[1][ft_strlen(arg[1]) - 1]))
		ft_exit_output("exit\n", ft_atoi(arg[1]) % 256, true);
}
