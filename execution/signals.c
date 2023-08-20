/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/20 13:50:42 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_herdoc_signal(int sig)
{
	if (sig == SIGINT && g_v.sig == 0)
	{
		write(1, "\n", 1);
		g_v.sig = -1;
		g_v.ex_stu = 1;
		rl_done = 1;
	}
}

void	ft_main_sig_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_v.ex_stu = 1;
}

void	ft_signals(void)
{
	signal(SIGINT, ft_main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
