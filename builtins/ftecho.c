/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/26 00:27:17 by khbouych         ###   ########.fr       */
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
	i = 2;
	if (ft_strcmp(arg[1], "echo") != 0)
		return ;
	if (!arg[2])
	{
		ft_putstr_fd("\n", fd);
		// write(1,"\n",fd);
		printf("\n");
		while (arg[i] && ft_check_n(arg[i]))
			i++;
		while (arg[i])
		{
			ft_putstr_fd(arg[i], fd);
			if (arg[i] && arg[i + 1])
				ft_putstr_fd(" ", fd);
			i++;
		}
		if (!ft_check_n(arg[2]))
			ft_putstr_fd("\n", fd);
	}
}
