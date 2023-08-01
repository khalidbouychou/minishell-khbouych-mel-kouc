/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/01 20:25:54 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_cd(char **cmd, t_env *env)
{
	t_env	*old;
	t_env	*pwd;
	t_env	*home;

	home = ft_getenv_node(env, "HOME");
	old = ft_getenv_node(env, "OLDPWD");
	pwd = ft_getenv_node(env, "PWD");

	if (old)
		old->value = getcwd(NULL, 0);
	if ((!cmd[1]))
	{
		puts("dfhdjfhdjsb\n");
		if (!home)
		{
			ft_putstr_fd("cd: HOME not set\n", 1);
			g_stu.ex_stu = 1;
		}
		else
			chdir(home->value);
		if (pwd)
			pwd->value = getcwd(NULL, 0);
		return ;
	}
	else if ((!ft_strcmp(cmd[1], "~")))
	{
		puts("dfhdjfhdjsb\n");
		if (!home)
			chdir("/Users/khbouych");
		else
			chdir(home->value);
		g_stu.ex_stu = 0;
		return ;
	}
	if (chdir(cmd[1]) == -1)
	{
		g_stu.ex_stu = 1;
		ft_putstr_fd("No such file or directory \n", 1);
		return ;
	}
	else
	{
		if (pwd)
			pwd->value = getcwd(NULL, 0);
	}
	g_stu.ex_stu = 0;
}
	// else
	// {
	// 	puts ("zzzz\n");
	// 	printf ("cd: error retrieving current directory:
	// 	getcwd: cannot access parent directories:
	// 	No such file or directory");
	// 	ft_getenv_node(env, "OLDPWD")->value = ft_strdup(g_stu.current_pwd);
	// 	g_stu.current_pwd = ft_strjoin(g_stu.current_pwd, "/..");
	// 	ft_getenv_node(env, "PWD")->value = ft_strdup(g_stu.current_pwd);
	// 	return ;
	// }