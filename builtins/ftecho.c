/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:37 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/21 10:09:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_check_n(char *arg)
{
	int	 i;
	int flag = 1;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] != 'n')
		{
			flag = 0;
			break ;
		}
		if (flag == 1)
			i++;
	}
	return (flag);
}

void	ft_echo(char **arg, int fd)
{
	int	i;
	int	j;
	int	nline;
	(void)fd;
	i = 2;
	j = 0;
	nline = ft_check_n(arg[2]);
	while (arg[i])
	{
		while (arg[i] && ft_check_n(arg[i]))
			i++;
		// write(fd, &arg[i++], 1);
		printf(" %s",arg[i++]);
	}
	if (!ft_check_n(arg[2]))
	{
		// write(1,"\n",fd);
		printf("\n");
		return ;
	}
}
