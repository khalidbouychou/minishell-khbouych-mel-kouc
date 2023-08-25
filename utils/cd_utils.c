/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:30:13 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/24 01:56:47 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*ft_get_env(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_getenv_node(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*ft_add_env(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	check_point(char **cmd, t_env **env)
{
	char	*tmp;
	t_env	*ptr;
	t_env	*str;

	tmp = NULL;
	ptr = ft_getenv_node((*env), "OLDPWD");
	if (ptr)
		ptr->value = ft_strdup(g_v.current_pwd);
	if (!ft_strcmp(*cmd, "."))
	{
		tmp = g_v.current_pwd;
		g_v.current_pwd = ft_strjoin(g_v.current_pwd, "/.");
		free(tmp);
	}
	else
	{
		tmp = g_v.current_pwd;
		g_v.current_pwd = ft_strjoin(g_v.current_pwd, "/..");
		free(tmp);
	}
	str = ft_getenv_node((*env), "PWD");
	if (str)
		str->value = ft_strdup(g_v.current_pwd);
}

void	ft_cd_(t_env **env, char **ret, char *cmd)
{
	char	*tmp;
	t_env	*ptr;
	t_env	*str;

	tmp = NULL;
	ptr = NULL;
	str = NULL;
	if (!(*ret))
	{
		ft_putstr_fd("cd: error retrieving current directory: ", 1);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 1);
		ft_putstr_fd("No such file or directory\n", 1);
		check_point(&cmd, env);
		return ;
	}
	else
	{
		tmp = g_v.current_pwd;
		g_v.current_pwd = (*ret);
		free(tmp);
	}
}
