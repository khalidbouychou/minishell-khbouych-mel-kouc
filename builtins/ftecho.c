/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/05 23:58:10 by khbouych         ###   ########.fr       */
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

void	ft_split_space(char *str, int fd)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i += 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			flg = 1;
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			if (flg)
				write(1, " ", fd);
			flg = 0;
			write(1, &str[i], fd);
		}
		i += 1;
	}
}
int	ft_detect_more_spaces(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == 32 && str[i + 1] == 32)
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(char **arg, int fd)
{
	int	i;

	i = 1;
	while (arg[i] && ft_check_n(arg[i]))
		i++;
	while (arg[i])
	{
		if (!ft_strcmp(arg[i], "?"))
			printf("%d", g_stu.ex_stu);
		else if (g_stu.v_q == 1)
		{
			printf("hhhhh\n");
			ft_split_space(arg[i], fd);
			g_stu.v_q = 0;
		}
		else if (g_stu.v_q == 0)
			ft_putstr_fd(arg[i], fd);
		i++;
	}
	if (0 != ft_strcmp(arg[1], "-n"))
		printf("\n");
}
