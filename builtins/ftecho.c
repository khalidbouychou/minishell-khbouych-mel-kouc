/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/30 16:37:02 by khbouych         ###   ########.fr       */
=======
/*   Updated: 2023/08/02 11:45:46 by mel-kouc         ###   ########.fr       */
>>>>>>> 87a8e2838827633f6c57364a790fa10f00152b9a
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
	if (!arg[1])
	{
		ft_putstr_fd("\n", fd);
		return ;
	}
	if (!ft_strcmp(arg[1], "?"))
		printf("%d\n", g_stu.ex_stu);
	else
	{
		if (arg[1])
		{
			while (arg[i] && ft_check_n(arg[i]))
				i++;
			while (arg[i])
				ft_putstr_fd(arg[i++], fd);
			if (!ft_check_n(arg[1]))
				ft_putstr_fd("\n", fd);
		}
		g_stu.ex_stu = 0;
	}
}
