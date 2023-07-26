/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/26 01:33:43 by mel-kouc         ###   ########.fr       */
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
	if (ft_strcmp(arg[0], "echo") != 0)
		return ;
	if (arg[1])
	{
		// ft_putstr_fd("\n", fd);
		while (arg[i] && ft_check_n(arg[i]))
			i++;
		while (arg[i])
		{
			ft_putstr_fd(arg[i], fd);
			// if (arg[i] && arg[i + 1])
			// 	ft_putstr_fd(" ", fd);
			i++;
		}
		if (!ft_check_n(arg[1]))
			ft_putstr_fd("\n", fd);
	}
}
