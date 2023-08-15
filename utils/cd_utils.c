/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:30:13 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/15 16:08:33 by mel-kouc         ###   ########.fr       */
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

void	env_not_exist(int i, char **key, char **value)
{
	if (i == 0)
	{
		*key = ft_strdup("PWD");
		*value = ft_strdup(g_stu.current_pwd);
		g_stu.current_pwd = *value;
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

int	ft_check_by_key(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
