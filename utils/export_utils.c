/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:56:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 13:54:11 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (1);
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

void	ft_print_after_sort(t_env *ee)
{
	t_env	*e;

	ft_sort_keys(ee);
	e = ee;
	while (e)
	{
		if (!e->value)
			printf("declare -x %s\n", e->key);
		else
			printf("declare -x %s=\"%s\"\n", e->key, e->value);
		e = e->next;
	}
}

char	*ft_get_key_without_plus(char *key)
{
	int		i;
	char	*str;

	i = 0;
	while (key[i] && key[i] != '+')
		i++;
	str = ft_substr(key, 0, i);
	return (str);
}

char	*ft_get_old_value(t_env *e, char *key)
{
	t_env	*tmp;

	tmp = e;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int ft_size_export(char **export)
{
	int size;

	size = 0;
	while (export[size])
		size++;
	return (size);
}
void	ft_export(char **export, t_env *env, int fd)
{
	if (export[1] == NULL)
	{
		ft_sort_keys(env);
		ft_print_after_sort(env);
		return ;
	}
	ft_help_export(export, env, fd);
}
