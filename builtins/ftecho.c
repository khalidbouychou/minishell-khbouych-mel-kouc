/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/18 14:11:15 by mel-kouc         ###   ########.fr       */
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
		// if (arg[i])
		// 	write(fd, " ", 1);
		i++;
	}
	if (!x)
		ft_putstr_fd("\n", fd);
	g_stu.ex_stu = 0;
}


// int	ft_check_n(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	if (arg[0] != '-')
// 		return (0);
// 	while (arg[++i])
// 	{
// 		if (arg[i] != 'n')
// 			return (0);
// 	}
// 	return (1);
// }

// void	ft_echo(char **arg, int fd)
// {
// 	int	i;

// 	i = 1;
// 	// printf("fd = %d\n", fd);
// 	if (!arg[1])
// 	{
// 		ft_putstr_fd("\n", fd);
// 		return ;
// 	}
// 	if (!ft_strcmp(arg[1], "?"))
// 		printf("%d\n", g_stu.ex_stu);
// 	else
// 	{
// 		if (arg[1])
// 		{
// 			while (arg[i] && ft_check_n(arg[i]))
// 				i++;
// 			while (arg[i])
// 				ft_putstr_fd(arg[i++], fd);
// 			if (!ft_check_n(arg[1]))
// 				ft_putstr_fd("\n", fd);
// 		}
// 		g_stu.ex_stu = 0;
// 	}
// }
