/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/21 11:38:28 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_check_ifkey_valid(char *key)
{
	int	i;

	i = 0;
	if (key[0] != '_' || key[ft_strlen(key) - 1] != '_'
		|| !ft_isalpha(key[0]) || !ft_isalpha(key[ft_strlen(key) - 1])
		|| key[ft_strlen(key) - 1] != '+')
	{
		ft_putstr_fd("[ export : Not a valid identifier ]\n", 2);
		return (0);
	}
	while (key[i])
	{
		if (key[i] != '_' && !ft_isalnum(key[i]))
		{
			ft_putstr_fd("[ export : Not a valid identifier ]\n", 2);
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

void	ft_sort_keys(char **tab_keys, int i, int j)
{
	char	*swap;

	if (!tab_keys[j])
		return ;
	if (ft_strcmp(tab_keys[i], tab_keys[j]) > 0)
	{
		swap = tab_keys[i];
		tab_keys[i] = tab_keys[j];
		tab_keys[j] = swap;
	}
	ft_sort_keys(tab_keys, i, j++);
	ft_sort_keys(tab_keys, i++, 0);
}

void	ft_print_export(char *key, char *value)
{
	if (value != NULL)
		printf ("declare -x %s=\"%s\"\n", key, value);
	else
		printf ("declare -x %s\n", key);
}

void	ft_print_after_sort(t_env *env, char **tab_keys)
{
	int		i;
	t_env	*head;

	head = env;
	while (head)
	{
		i = 0;
		while (tab_keys[i])
		{
			if (!ft_strcmp(head->key, tab_keys[i]))
			{
				ft_print_export(tab_keys[i], head->value);
				break ;
			}
			i++;
		}
		head = head->next;
	}
}

void	ft_sorting_export(t_env *env)
{
	int		size;
	char	**tab_keys;
	t_env	*head_env;
	int		i;
	int		j;

	head_env = env;
	tab_keys = NULL;
	i = 0;
	j = 0;
	size = 0;
	head_env = env;
	while (head_env)
	{
		size += 1;
		head_env = head_env->next;
	}
	tab_keys = ft_get_keys_tab(env, size);
	ft_sort_keys(tab_keys, i, j);
	ft_print_after_sort(env, tab_keys);
}

// int	ft_exp_vars(char *exp,t_env **env)
// {

// }

void	ft_export(char **export , t_env **env)
{
	t_env	*_env;
	int		i;

	_env = (*env);
	i = 1;
	if (export[i])
	{
		while (export[i])
		{
			// ft_exp_vars(export[i], env);
			i++;
			return ;
		}
	}
	else
	{
		ft_sorting_export(_env);
		return ;
	}
}
