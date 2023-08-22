/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 02:44:40 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_env(t_parse *penv, t_env **env)
{
	t_env	*tmp;

	if (!ft_strncmp(penv->arg[0], "env", ft_strlen(penv->arg[0]))
		&& penv->arg[1] != NULL)
		ft_exit_output("env: No such file or directory\n", 17, false);
	else
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
	}
	g_v.ex_stu = 0;
}
