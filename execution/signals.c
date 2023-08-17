/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/17 11:34:36 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_herdoc_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_v.sig = -1;
		g_v.ex_stu = 1;
		rl_done = 1;
	}
}

void	ft_main_sig_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	if (sig)
		rl_catch_signals = 0;
	g_v.ex_stu = 1;
}

void	ft_quit_handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	ft_putstr_fd("Quit: ", 1);
	ft_putstr_fd("\n", 1);
}

void	ft_signals(void)
{
	signal(SIGINT, ft_main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
