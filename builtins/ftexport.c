/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/22 15:28:09 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_check_ifkey_valid(char *key, int fd)
{
	int	i;

	i = 0;
	if (key[0] != '_' || key[ft_strlen(key) - 1] != '_'
		|| !ft_isalpha(key[0]) || !ft_isalpha(key[ft_strlen(key) - 1])
		|| key[ft_strlen(key) - 1] != '+')
	{
		ft_putstr_fd("[export : Not a valid identifier ]\n", fd);
		return (0);
	}
	while (key[i])
	{
		if (key[i] != '_' && !ft_isalnum(key[i]))
		{
			ft_putstr_fd("[export : Not a valid identifier ]\n", fd);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_get_keys_tab(t_env *env, int size)
{
	char	**res;
	t_env	*head;
	int		i;

	i = -1;
	head = env;
	res = (char **)malloc(sizeof(char *) * size + 1);
	while (head)
	{
		if (head->key != NULL)
			res[++i] = ft_strdup(head->key);
		head = head->next;
	}
	res[i] = NULL;
	return (res);
}

void	ft_export(char **export, t_env *env, int fd)
{
	int		i;
	// int		size;
	// char	**tkeys;
	t_env	*node;

	// size = 0;
	node = NULL;
	// tkeys = NULL;
	i = 2;
	// size = ft_get_size_of_list(env);
	// tkeys = ft_get_keys_tab(env, size);
	if (ft_strcmp("export", export[1]) > 0)
	{
		ft_putstr_fd("[error] -->command not found", fd);
		return ;
	}
	else
	{
		while (export[i])
		{
			node = ft_lstnew(export[i]);
			if (!ft_is_key_exist(node->key,
					ft_get_keys_tab(env, ft_get_size_of_list(env))))
			{
				ft_lst_addback(&env, node);
			}
			i++;
		}
	}
	ft_sort_keys(ft_get_keys_tab(env, ft_get_size_of_list(env)));
	ft_print_after_sort(env, ft_get_keys_tab(env, ft_get_size_of_list(env)));
}
