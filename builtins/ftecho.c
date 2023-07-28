/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/27 15:38:58 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_check_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] != '-')
		return (0);
	while (arg[++i])
	{
		if (arg[i] != 'n')
			return (0);
	}
	return (1);
}

void	ft_echo(char **arg, int fd)
{
	int	i;

	i = 1;
	if (ft_strncmp(arg[i], "$?", 3) == 0)
	{
		g_stu.ex_stu = 1;
		if (!arg[i + 1])
			printf("%d", g_stu.ex_stu);
		else
			printf("%d", g_stu.ex_stu);
	}
	if (arg[1])
	{
		while (arg[i] && ft_check_n(arg[i]))
			i++;
		while (arg[i])
			ft_putstr_fd(arg[i++], fd);
		if (!ft_check_n(arg[1]))
			ft_putstr_fd("\n", fd);
	}
	g_stu.ex_stu = EXIT_SUCCESS;
}
