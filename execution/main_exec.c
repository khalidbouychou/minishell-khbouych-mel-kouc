/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:44:27 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/28 19:57:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	check_cmd_built(t_parse *list_pars, t_env *env)
{
	t_parse	*tmp;

	(void)env;
	tmp = list_pars;
	while (tmp)
	{
		if (!ft_strcmp(tmp->arg[0], "echo"))
		{
			// printf("\n----->test echo\n");
			ft_echo(tmp->arg, 1);
		}
		else if (!ft_strcmp(tmp->arg[0], "env"))
		{
			printf("\n----->test env \n");
		}
		else if (!ft_strcmp(tmp->arg[0], "export"))
		{
			printf("\n----->test export\n");
			// ft_export(tmp->arg, tmp->fd_output);
		}
		else if (!ft_strcmp(tmp->arg[0], "pwd"))
		{
			printf("\n----->test pwd\n");
		}
		else if (!ft_strcmp(tmp->arg[0], "exit"))
		{
			ft_exit(tmp->arg);
			// printf("\n----->test exit\n");
		}
		else if (!ft_strcmp(tmp->arg[0], "unset"))
		{
			// ft_unset()
			printf("\n----->test unset\n");
		}
		else if (!ft_strcmp(tmp->arg[0], "cd"))
		{
			printf("\n----->test cd\n");
		}
		tmp = tmp->next;
	}
}

void    execute_main(t_parse *list_pars, t_env *env)
{
	check_cmd_built(list_pars, env);
}
