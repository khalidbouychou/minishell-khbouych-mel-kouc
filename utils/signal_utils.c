/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:41:17 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 19:05:42 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_default_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	ftstatus(int *status)
{
	if (WIFEXITED(*status))
		g_v.ex_stu = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
	{
		if (WTERMSIG(*status) == SIGQUIT)
			ft_putendl_fd("Quit: 3", 2);
	}
}

char	*generate_name(void)
{
	char		*str;
	char		*count;
	int static	i;

	i++;
	str = "herdoc";
	count = ft_itoa(i);
	str = ft_strjoin(str, count);
	free(count);
	return (str);
}
