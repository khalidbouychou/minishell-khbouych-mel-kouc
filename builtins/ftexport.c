/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/27 15:33:22 by khbouych         ###   ########.fr       */
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

void	ft_add_to_env(t_env *e, t_env *node)
{
	node->prev = ft_lstlast(e);
	node->key = ft_get_key_without_plus(node->key);
	ft_lst_addback(&e, node);
}

void	ft_export(char **export, t_env *env, int fd)
{
	int		i;
	t_env	*node;

	if (export[2] == NULL)
	{
		ft_sort_keys(env);
		ft_print_after_sort(env);
		return ;
	}
	i = 2;
	while (export[i])
	{
		node = ft_lstnew(export[i++]);
		if (ft_check_ifkey_valid(node, fd))
		{
			if (node->key[ft_strlen(node->key) - 1] == '+'
				&& ft_if_key_exist(env, node))
				ft_join_value(env, node);
			else
				ft_add_to_env(env, node);
		}
	}
	g_stu.ex_stu = EXIT_SUCCESS;
}
