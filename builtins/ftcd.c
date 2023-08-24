/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/24 11:44:20 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_help__cd(t_env *home)
{
	if (!home)
		chdir("/Users/khbouych");
	else
		chdir(home->value);
	g_v.ex_stu = 0;
}

int	cmd_condition(char **cmd, t_env	*home, t_env *pwd)
{
	if ((!cmd[1]))
	{
		ft_help_cd(home, pwd);
		return (0);
	}
	else if ((!ft_strcmp(cmd[1], "~")))
	{
		ft_help__cd(home);
		return (0);
	}
	if (chdir(cmd[1]) == -1)
	{
		g_v.ex_stu = 1;
		ft_putstr_fd("No such file or directory \n", 2);
		return (0);
	}
	else
	{
		if (pwd)
		{
			free(pwd->value);
			pwd->value = getcwd(NULL, 0);
		}
	}
	return (1);
}

void	ft_cd(char **cmd, t_env *env)
{
	t_env	*old;
	t_env	*pwd;
	t_env	*home;
	char	*ret;

	home = NULL;
	pwd = NULL;
	old = NULL;
	ret = NULL;
	ft_init_env(&home, &pwd, &old, env);
	if (cmd[1] && !*cmd[1])
		return ;
	if (cmd_condition(cmd, home, pwd) == 0)
		return ;
	ret = getcwd(NULL, 0);
	ft_cd_(&env, &ret, cmd[1]);
	g_v.ex_stu = 0;
}
