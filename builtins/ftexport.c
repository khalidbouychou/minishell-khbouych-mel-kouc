/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/20 11:20:47 by mel-kouc         ###   ########.fr       */
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
			str = tmp->key;
			ptr = tmp->value;
			tmp->key = node->key;
			tmp->value = node->value;
			free(str);
			free(ptr);
			free(node);
		}
		tmp = tmp->next;
	}
}

void	not_valid_key(t_env	**node)
{
	free((*node)->key);
	if ((*node)->value)
		free((*node)->value);
	free((*node));
	ft_exit_output("", 1, false);
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
			else
				ft_add_to_env(env, node);
		}
		else
		{
			not_valid_key(&node);
			return (g_v.ex_stu = 1);
		}
	}
	return (g_v.ex_stu = 0);
}
