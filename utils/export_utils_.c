/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:44:30 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/13 19:05:27 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_is_key_exist(char *key, char **tkeys)
{
	int	i;

	i = 0;
	while (tkeys[i])
	{
		if (ft_strcmp(tkeys[i], key) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_keys(t_env *e)
{
	t_env	*tmp;
	t_env	*ptr;
	char	*x;
	char	*v;

	tmp = e;
	while (tmp)
	{
		ptr = tmp->next;
		while (ptr)
		{
			if (tmp->key[0] > ptr->key[0])
			{
				x = tmp->key;
				tmp->key = ptr->key;
				ptr->key = x;
				v = tmp->value;
				tmp->value = ptr->value;
				ptr->value = v;
			}
			ptr = ptr->next;
		}
		tmp = tmp->next;
	}
}

int	ft_if_key_exist(t_env *e, t_env *node)
{
	t_env	*tmp;

	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(ft_get_key_without_plus(node->key), tmp->key))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_join_value(t_env *e, t_env *node)
{
	t_env	*tmp;

	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(ft_get_key_without_plus(node->key), tmp->key))
			tmp->value = ft_strjoin(tmp->value, node->value);
		tmp = tmp->next;
	}
}
