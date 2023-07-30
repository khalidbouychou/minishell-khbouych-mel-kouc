/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:56:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/30 13:55:46 by khbouych         ###   ########.fr       */
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

// int	ft_get_size_of_list(t_env *env)
// {
// 	int		i;
// 	t_env	*e;

// 	i = 0;
// 	e = env;
// 	while (e)
// 	{
// 		i++;
// 		e = e->next;
// 	}
// 	return (i);
// }

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
	int	i;

	i = 0;
	while (key[i] && key[i] != '+')
		i++;
	return (ft_substr(key, 0, i));
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
