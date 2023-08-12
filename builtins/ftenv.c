/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/10 21:43:09 by khbouych         ###   ########.fr       */
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
		g_stu.ex_stu = 0;
	}
	else
		ft_exit_output("--> No such file or directory\n", 1, false);
}
