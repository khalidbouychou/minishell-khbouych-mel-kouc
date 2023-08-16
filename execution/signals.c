/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/16 18:07:35 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void    ft_main_sig_handler(int sig)
{
    (void) sig;
    if (!access("/tmp/herdoc", F_OK))
    {
        close(0);
        ft_putstr_fd("\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        // exit(0);
        return;
    }
    if(g_stu.sig == 0)
        ft_putstr_fd("\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    g_stu.ex_stu = 1;

}

void    ft_signals(void)
{
    signal(SIGINT, ft_main_sig_handler);
    signal(SIGQUIT, SIG_IGN);
}
// void	sig_handler(int signal)
// {
// 	ft_putstr_fd("\n", 1);
// 	if (signal == SIGINT && g_stu.is_p == 0)
// 	{
// 		// rl_catch_signals = 0;
// 		// rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 		// g_stu.ex_stu = 1;
// 	}
// }

// void	ft_signals(void)
// {
// 	signal(SIGINT, sig_handler);
// 	signal(SIGQUIT, SIG_IGN);
// }
