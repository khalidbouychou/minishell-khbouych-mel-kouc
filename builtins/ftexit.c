/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:45 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/27 18:40:52 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_exit(char **arg)
{
	if (arg[3])
	{
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("too many arguments\n", 1);
		g_stu.ex_stu = 1;
		exit (g_stu.ex_stu);
		return ;
	}
	else if (!arg[2])
	{
		write(1, "exit\n", 6);
		g_stu.ex_stu = 0;
		exit(g_stu.ex_stu);
	}
	else if ((!ft_check_arg_is_digit(arg[2])))
	{
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("numeric argument required\n", 1);
		g_stu.ex_stu = 255;
		exit(g_stu.ex_stu);
	}
	else if (ft_check_arg_is_digit(arg[2]))
	{
		if (ft_check_overflow(arg[2]))
		{
			puts("1\n");
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("numeric argument required\n", 1);
			exit (g_stu.ex_stu);
		}
		else
		{
			puts("0\n");
			ft_putstr_fd("exit\n", 1);
			exit (g_stu.ex_stu);
		}
	}
}
