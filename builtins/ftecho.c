/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/15 23:52:12 by mel-kouc         ###   ########.fr       */
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
	int	x;

	i = 1;
	x = 0;
	while (arg[i] && ft_check_n(arg[i]))
	{
		x = 1;
		i++;
	}
	while (arg[i])
	{
		if (ft_strcmp("?", arg[i]) == 0)
			ft_putnbr(g_stu.ex_stu);
		else 
			ft_putstr_fd(arg[i], fd);
		i++;
	}
	if (!x)
		ft_putstr_fd("\n", fd);
	g_stu.ex_stu = 0;
}
