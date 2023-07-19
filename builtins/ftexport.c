/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftexport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:47 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/19 18:39:30 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

// void	ft_strlcpy(char *dst, char *src, int dstsize)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i] && i < dstsize)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// }

// void	ft_strcpy(char* dest, const char* src)
// {
//     if (dest == NULL || src == NULL)
//         return ;

//     char* ptr = dest;

//     while (*src != '\0') {
//         *ptr = *src;
//         ptr++;
//         src++;
//     }
//     *ptr = '\0';
// }

void	ft_hard_copy(char *k ,char *v, t_env *e1, t_env *e2)
{
	ft_strcpy(k, e1->key);
	ft_strcpy(v, e1->value);
	ft_strcpy(e1->key, e2->key);
	ft_strcpy(e1->value, e2->value);
	ft_strcpy(e1->key, k);
	ft_strcpy(e1->value, v);
}

void	ft_sortlist(t_env *cpy_env)
{
	int		i;
	t_env	*tmp;
	t_env	*next;
	char	*_key = NULL;
	char	*_value = NULL;

	i = 0;
	tmp = cpy_env;
	next = cpy_env->next;
	while (tmp && next)
	{
		if (tmp->key[0] > next->key[0])
		{
			// puts("ddd\n");
			ft_hard_copy(_key, _value, tmp, next);
		}
		tmp = tmp->next;
		next = next->next;
	}
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

void	ft_export(char **arg, t_env *env)
{
	(void)arg;
	ft_sortlist(env);
	ft_print_env(env);
}
