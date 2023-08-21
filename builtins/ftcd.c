/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 15:28:09 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	update_oldpwd(t_env *env, t_env *old)
{
	old = ft_getenv_node(env, "OLDPWD");
	if (old)
		old->value = getcwd(NULL, 0);
}

void	ft_init_env(t_env **home, t_env **pwd, t_env **old, t_env *env)
{
	(*home) = ft_getenv_node(env, "HOME");
	(*old) = ft_getenv_node(env, "OLDPWD");
	(*pwd) = ft_getenv_node(env, "PWD");
	update_oldpwd(env, (*old));
}

void	ft_help_cd(t_env *home, t_env *pwd)
{
	if (!home)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		g_v.ex_stu = 1;
	}
	else
		chdir(home->value);
	if (pwd)
		pwd->value = getcwd(NULL, 0);
}

void	ft_help__cd(t_env *home)
{
	if (!home)
		chdir("/Users/khbouych");
	else
		chdir(home->value);
	g_v.ex_stu = 0;
}

void	ft_cd(char **cmd, t_env *env)
{
	t_env	*old;
	t_env	*pwd;
	t_env	*home;
	char	*ret;

	ft_init_env(&home, &pwd, &old, env);
	if (cmd[1] && !*cmd[1])
		return ;
	if ((!cmd[1]))
	{
		ft_help_cd(home, pwd);
		return;
	}
	else if ((!ft_strcmp(cmd[1], "~")))
	{
		ft_help__cd(home);
		return ;
	}
	if (chdir(cmd[1]) == -1)
	{
		g_v.ex_stu = 1;
		ft_putstr_fd("No such file or directory \n", 2);
		return ;
	}
	else
		if (pwd)
			pwd->value = getcwd(NULL, 0);
	ret = getcwd(NULL, 0);
	ft_cd_(&env, &ret, cmd[1]);
	g_v.ex_stu = 0;
}
