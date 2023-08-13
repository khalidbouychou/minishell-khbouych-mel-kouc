/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/13 19:08:34 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_check_ifkey_valid(t_env *node, int fd)
{
	int	i;

	i = 0;
	if (node->key[ft_strlen(node->key) - 1] == '+' && node->value == NULL)
		return (write(fd, "[export : key not valide ]\n", 28), 0);
	if (!ft_isalpha(node->key[0]) && node->key[0] != '_')
		return (write(fd, "[export : key not valide ]\n", 28), 0);
	if (node->key[ft_strlen(node->key) - 1] != '_'
		&& !ft_isalnum(node->key[ft_strlen(node->key) - 1])
		&& node->key[ft_strlen(node->key) - 1] != '+')
		return (write(fd, "[export : key not valide ]\n", 28), 0);
	while (node->key[i] && node->key[i + 1])
	{
		if (node->key[i] != '_' && !ft_isalnum(node->key[i]))
			return (write(fd, "[export : key not valide ]\n", 28), 0);
		i++;
	}
	return (1);
}

void	ft_add_to_env(t_env *e, t_env *node)
{
	node->key = ft_get_key_without_plus(node->key);
	ft_lst_addback(&e, node);
}

t_env	*ft_getadress_node(t_env *env, t_env *node)
{
	while (env)
	{
		if (!ft_strcmp(env->key, node->key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

int	ft_help_export(char **export, t_env *env, int fd)
{
	int		i;
	t_env	*node;

	i = 1;
	while (export[i])
	{
		node = ft_lstnew(export[i++]);
		if (ft_check_ifkey_valid(node, fd))
		{
			if (node->key[ft_strlen(node->key) - 1] == '+'
				&& ft_if_key_exist(env, node))
				ft_join_value(env, node);
			else if (ft_if_key_exist(env, node))
				ft_getadress_node(env, node)->value = node->value;
			else
				ft_add_to_env(env, node);
		}
		else
		{
			ft_exit_output("", 1, false);
			return (g_stu.ex_stu = 1);
		}
	}
	return (g_stu.ex_stu = 0);
}
