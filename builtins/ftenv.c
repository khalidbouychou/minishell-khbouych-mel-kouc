/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/03 14:55:34 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_env(char **echo, t_env **env)
{
	t_env *tmp;
	// if (!echo[1])
	// {
		tmp = *env;
		(void)echo;
		if(!*env)
			puts("env khawiiii");
		while (tmp)
		{
			if (tmp->value)
				printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
		// ft_print_env((*env));
		g_stu.ex_stu = 0;
	// }
	// else
	// 	ft_exit_output("--> No such file or directory\n", 1, false);
}
