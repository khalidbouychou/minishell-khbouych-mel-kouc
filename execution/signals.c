/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/18 16:36:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_herdoc_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_v.catch_cntrl = true;
		g_v.sig = -1;
		g_v.ex_stu = 1;
		rl_done = 1;
	}
}

void	ftherdoc_signal(void (*f))
{
	signal(SIGINT, ft_herdoc_signal);
	rl_event_hook = f;
}

void	ft_main_sig_handler(int sig)
{
	if (sig == SIGINT && g_v.inside_m == 0)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		rl_catch_signals = 0;
		g_v.ex_stu = 1;
	}
	else if (sig == SIGINT && g_v.inside_m == 1)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		rl_catch_signals = 0;
	}
	g_v.ex_stu = 1;
}

void	ft_signals(void)
{
	signal(SIGINT, ft_main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
}
