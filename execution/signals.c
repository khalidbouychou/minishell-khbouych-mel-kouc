/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 04:00:34 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 16:26:08 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_herdoc_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_v.sig = -1;
		g_v.ex_stu = 1;
		rl_done = 1;
	}
}

void	ft_main_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line ();
		rl_replace_line("", 0);
		rl_redisplay ();
		g_v.ex_stu = 1;
	}
}

void	ft_child_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_v.ex_stu = 1;
	}
}

void	ft_signals(void)
{
	signal(SIGINT, ft_main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
