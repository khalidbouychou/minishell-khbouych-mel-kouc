/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/29 20:02:10 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_env(char **echo, t_env *env)
{
	if (!echo[1])
	{
		while (env)
		{
			if(env->value)
				printf("%s=%s\n", env->key, env->value);
			env = env->next;
		}
		g_stu.ex_stu = 0;
	}
	else
		ft_exit_output("--> No such file or directory\n", 127, false);
}
