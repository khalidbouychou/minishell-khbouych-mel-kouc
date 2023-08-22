/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:10:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 16:47:13 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	update_oldpwd(t_env *env, t_env *old)
{
	old = ft_getenv_node(env, "OLDPWD");
	if (old)
	{
		free(old->value);
		old->value = getcwd(NULL, 0);
	}
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
	{
		free(pwd->value);
		pwd->value = getcwd(NULL, 0);
	}
}

void	env_not_exist(int i, char **key, char **value)
{
	if (i == 0)
	{
		*key = ft_strdup("PWD");
		*value = ft_strdup(g_v.current_pwd);
	}
	else if (i == 1)
	{
		*key = ft_strdup("SHLVL");
		*value = ft_strdup("1");
	}
	else if (i == 2)
	{
		*key = ft_strdup("_");
		*value = ft_strdup("/usr/bin/env");
	}
	else if (i == 3)
	{
		*key = ft_strdup("PATH");
		*value = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	}
}
