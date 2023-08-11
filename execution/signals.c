/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/11 22:11:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_catch_signals = 0;
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_putstr_fd("\n", 1);
		rl_redisplay();
		g_stu.ex_stu = 1;
	}
}

void	ft_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
