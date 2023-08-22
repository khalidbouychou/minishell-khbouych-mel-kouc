/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 19:20:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_check_ifkey_valid(t_env *node, int fd)
{
	int	i;

	i = 0;
	if (node->key[0] == '\0')
		return (write(fd, "[export : key not valide ]\n", 28), 0);
	else if (node->key[ft_strlen(node->key) - 1] == '+' && node->value == NULL)
		return (write(fd, "[export : key not valide ]\n", 28), 0);
	else if (!ft_isalpha(node->key[0]) && node->key[0] != '_')
		return (write(fd, "[export : key not valide ]\n", 28), 0);
	else if (node->key[ft_strlen(node->key) - 1] != '_'
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
	char	*str;
	char	*tmp;

	str = node->key;
	tmp = ft_get_key_without_plus(str);
	free(str);
	node->key = tmp;
	ft_lst_addback(&e, node);
}

void	ft_getadress_node(t_env **env, t_env *node)
{
	char	*str;
	char	*ptr;
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, node->key))
		{
			if (tmp->value)
			{
				str = tmp->key;
				ptr = tmp->value;
				tmp->key = node->key;
				if (node->value)
					tmp->value = node->value;
			}
			free(str);
			free(ptr);
			free(node);
		}
		tmp = tmp->next;
	}
}

void	ft_free_export_node(t_env *node)
{
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
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
				ft_getadress_node(&env, node);
			else if (!ft_if_key_exist(env, node))
				ft_add_to_env(env, node);
		}
		else
		{
			ft_free_export_node(node);
			ft_exit_output("", 1, false);
			return (g_v.ex_stu = 1);
		}
	}
	return (g_v.ex_stu = 0);
}
