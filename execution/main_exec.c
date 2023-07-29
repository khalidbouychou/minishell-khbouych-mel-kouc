/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:44:27 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/29 17:09:09 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	check_cmd_built(t_parse *list_pars, t_env *env)
{
	t_parse	*tmp;

	tmp = list_pars;
	while (tmp)
	{
		ft_tolower(*tmp->arg);
		if (!ft_strcmp(tmp->arg[0], "echo"))
			ft_echo(tmp->arg, 1);
		else if (!ft_strcmp(tmp->arg[0], "env"))
			ft_env(tmp->arg, env);
		else if (!ft_strcmp(tmp->arg[0], "export"))
			ft_export(tmp->arg, env, tmp->fd_output);
		else if (!ft_strcmp(tmp->arg[0], "pwd"))
			ft_pwd();
		else if (!ft_strcmp(tmp->arg[0], "exit"))
			ft_exit(tmp->arg);
		else if (!ft_strcmp(tmp->arg[0], "unset"))
			ft_unset(env, tmp->arg);
		else if (!ft_strcmp(tmp->arg[0], "cd"))
			ft_cd(tmp->arg);
		tmp = tmp->next;
	}
}

void	execute_main(t_parse *list_pars, t_env *env)
{
	check_cmd_built(list_pars, env);
}
