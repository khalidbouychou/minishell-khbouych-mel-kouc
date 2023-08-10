/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/10 21:01:57 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_exe_sig_handler(int signal)
{
	if (signal == SIGINT)
		printf("\n");
}

void	ft_signal_execution(void)
{
	signal(SIGINT, ft_exe_sig_handler);
	signal(SIGQUIT, ft_exe_sig_handler);
}


void	ft_main_sig_handler(int signal)
{
	if(signal == SIGINT && g_stu.ex_stu != -1)
	{
		rl_catch_signals = 0;
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_stu.ex_stu = 1;
	}
}

// void	ft_quit_handler(int signal)
// {
// 	(void)signal;
// 	int len;
// 	len = ft_strlen(rl_line_buffer);
// 	if (len == 0)
// 	{
// 		printf("exit");
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// 	if (len != 0)
// 	{
// 		printf("Quit : 3");
// 		exit(g_stu.ex_stu = 131);
// 	}
// }
void	ft_signals(void)
{
	signal(SIGINT, ft_main_sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
