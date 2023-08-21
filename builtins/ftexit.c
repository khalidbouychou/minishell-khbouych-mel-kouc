/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:45 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 03:45:16 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_exit_output(char *msg, int exit_status, bool _bool)
{
	ft_putstr_fd(msg, 2);
	if (_bool)
		exit(g_v.ex_stu = exit_status);
	else
		g_v.ex_stu = exit_status;
}

void	ft_exit(char **arg)
{
	if (!ft_strcmp(arg[0], "exit") && arg[1] == NULL)
		ft_exit_output("exit\n", 0, true);
	else if (ft_arg_digit(arg[1]) && arg[2] == NULL)
		ft_exit_output("exit\n", ft_atoi(arg[1]), true);
	else if ((ft_arg_digit(arg[1]) && ft_arg_digit(arg[2]))
		|| (ft_arg_digit(arg[1]) && !ft_arg_digit(arg[2])))
		ft_exit_output("exit\n --> too many arguments\n", 1, false);
	else if (ft_isdigit(arg[1][ft_strlen(arg[1]) - 1])
		&& ((ft_atoi(arg[1]) < 0 || ft_atoi(arg[1]) > 256)))
		ft_exit_output("exit\n", ft_atoi(arg[1]) % 256, true);
	else if (!ft_arg_digit(arg[1]))
		ft_exit_output("exit\n--> numeric argument required\n", 255, true);
}
