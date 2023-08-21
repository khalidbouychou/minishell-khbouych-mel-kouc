/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:44:30 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 22:12:17 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

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
	char	*str;

	tmp = e;
	str = ft_get_key_without_plus(node->key);
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->key))
		{
			free(str);
			return (1);
		}
		tmp = tmp->next;
	}
	free(str);
	return (0);
}

void	ft_join_value(t_env *e, t_env *node)
{
	t_env	*tmp;
	char	*str;
	char	*ptr;

	str = ft_get_key_without_plus(node->key);
	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(str, tmp->key))
		{
			ptr = tmp->value;
			tmp->value = ft_strjoin(ptr, node->value);
			free(ptr);
			free(str);
			free(node->key);
			free(node->value);
			free(node);
		}
		tmp = tmp->next;
	}
}
