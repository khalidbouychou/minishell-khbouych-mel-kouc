/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 11:50:53 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_env(t_parse *penv, t_env **env)
{
	t_env	*tmp;

	if (!penv->arg[1])
	{
		tmp = *env;
		while (tmp)
		{
			if (tmp->value)
			{
				ft_putstr_fd(tmp->key, penv->fd_output);
				ft_putstr_fd("=", penv->fd_output);
				ft_putstr_fd(tmp->value, penv->fd_output);
				ft_putstr_fd("\n", penv->fd_output);
			}
			tmp = tmp->next;
		}
		g_v.ex_stu = 0;
	}
	else
		ft_exit_output("--> illegal option \n", 1, false);
}
