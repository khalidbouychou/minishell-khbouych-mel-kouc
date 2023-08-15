/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/15 16:33:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_main_sig_handler(int signal)
{
	(void) signal;
	rl_catch_signals = 0;
	if (g_stu.sig == 1 && signal == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		ft_putstr_fd("\n", 1);
		g_stu.ex_stu = 1;
	}
}

void	ft_signals(void)
{
	signal(SIGINT, ft_main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
