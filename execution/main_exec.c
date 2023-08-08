/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:44:27 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/08 16:28:19 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	cmd_in_built(t_parse *list_pars, t_env **env)
{
	t_parse	*tmp;

	tmp = list_pars;
	ft_tolower(*tmp->arg);
	if (tmp->fd_input == -1 || tmp->fd_output == -1 || g_stu.flag == 1)
		g_stu.flag = 0;
	else if (!ft_strcmp(tmp->arg[0], "echo"))
		ft_echo(tmp->arg, tmp->fd_output);
	else if (!ft_strcmp(tmp->arg[0], "env"))
		ft_env(tmp, env);
	else if (!ft_strcmp(tmp->arg[0], "export"))
		ft_export(tmp->arg, *env, tmp->fd_output);
	else if (!ft_strcmp(tmp->arg[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(tmp->arg[0], "exit"))
		ft_exit(tmp->arg);
	else if (!ft_strcmp(tmp->arg[0], "unset"))
		ft_unset(env, tmp->arg);
	else if (!ft_strcmp(tmp->arg[0], "cd"))
		ft_cd(tmp->arg, *env);
}

void	execute_main(t_parse *list_pars, t_env **env)
{
	char	**str;

	str = NULL;
	str = list_to_char(*env, str);
	if (!list_pars->next)
	{
		if (compare_cmd(list_pars))
			cmd_in_built(list_pars, env);
		else if (g_stu.flag == 1)
			g_stu.flag = 0;
		else
			simple_not_built(list_pars, *env, str);
	}
	else
		complex_cmd(list_pars, *env, str);
	// free_char_double(str);
	// free_char_double(list_pars->arg);
}
