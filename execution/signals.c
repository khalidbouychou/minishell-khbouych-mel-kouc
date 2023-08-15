/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:05:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/15 17:48:53 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void    ft_main_sig_handler(int signal)
{
    (void) signal;
    if (g_stu.sig)
    {
        rl_catch_signals = 0;
        ft_putstr_fd("\n", 1);
        rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
        g_stu.ex_stu = 1;
    }
}

void    ft_signals(void)
{
    signal(SIGINT, ft_main_sig_handler);
    signal(SIGQUIT, SIG_IGN);
}
