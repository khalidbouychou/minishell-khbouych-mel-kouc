/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/07 15:35:30 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_env(char **echo, t_env **env)
{
	t_env	*tmp;

	if (!echo[1])
	{
		tmp = *env;
		while (tmp)
		{
			if (tmp->value)
			{
				ft_putstr_fd(tmp->key,1);
				ft_putstr_fd("=",1);
				ft_putstr_fd(tmp->value,1);
				ft_putstr_fd("\n",1);
			}
				// printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
		g_stu.ex_stu = 0;
	}
	else
		ft_exit_output("--> No such file or directory\n", 1, false);
}
