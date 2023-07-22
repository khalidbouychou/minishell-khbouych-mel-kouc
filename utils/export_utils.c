/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:56:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/22 10:01:23 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1 && !str2)
		return (0);
	if (!str1 || !str2)
		return (1);
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	ft_get_size_of_list(t_env *env)
{
	int		i;
	t_env	*e;

	i = 0;
	e = env;
	while (e)
	{
		i++;
		e = e->next;
	}
	return (i);
}

void	ft_sort_keys(char **t_keys)
{
	char	*swap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!t_keys[j])
		return ;
	while (t_keys[i])
	{
		j = 0;
		while (t_keys[j])
		{
			if (ft_strcmp(t_keys[i], t_keys[j]) < 0)
			{
				swap = t_keys[i];
				t_keys[i] = t_keys[j];
				t_keys[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_export(char *key, char *value)
{
	if (value != NULL)
		printf ("declare -x %s=\"%s\"\n", key, value);
	else
		printf ("declare -x %s\n", key);
}

void	ft_print_after_sort(t_env *e, char **tkeys)
{
	int		i;
	t_env	*h;

	i = 0;
	while (tkeys[i])
	{
		h = e;
		while (h)
		{
			if (!ft_strcmp(h->key, tkeys[i]))
				ft_print_export(h->key, h->value);
			h = h->next;
		}
		i++;
	}
}
