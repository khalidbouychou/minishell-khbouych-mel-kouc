/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/19 15:50:34 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
}

void	ft_hard_copy(char *k char *v, t_env *e1, t_env *e2)
{
	ft_strlcpy(k, e1->key, ft_strlen(e1->key));
	ft_strlcpy(v, e1->value, ft_strlen(e1->value));
	ft_strlcpy(e1->key, e2->key, ft_strlen(e2->key));
	ft_strlcpy(e1->value, e2->value, ft_strlen(e2->value));
	ft_strlcpy(e1->key, k, ft_strlen(k));
	ft_strlcpy(e1->value, v, ft_strlen(v));
}

int	ft_sortlist(t_env *cpy_env)
{
	int		i;
	t_env	*tmp;
	t_env	*next;
	char	*_key;
	char	*_value;

	i = 0;
	tmp = cpy_env;
	next = tmp->next;
	while (tmp)
	{
		if (tmp->key[0] > next->key[0])
			ft_hard_copy(_key, _value, tmp, next);
		tmp = tmp.next;
	}
	return (0);
}

int	ft_check_ifkey_valid(char *key)
{
	int	i;

	i = 0;

	if (key[0] != '_' || key[ft_strlen(key) - 1] != '_'
		|| !ft_isalpha(key[0]) || !ft_isalpha(key[ft_strlen(key) - 1])
		|| key[ft_strlen(key) - 1] != '+')
		return (0);
	while (key[i])
	{
		if (key[i] != '_' && !ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_export(char **arg, t_env *env)
{
	return (1);
}