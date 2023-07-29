/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftunset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/29 17:21:48 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_key_syntax(char *key)
{
	int	i;

	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	if (!ft_isalnum(key[ft_strlen(key) - 1]))
		return (0);
	i = 1;
	while (key[i])
	{
		if (key[i] != '_' && !ft_isalnum(key[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_delete_node(t_env **e_lst, char *key)
{
	t_env	*tmp;

	tmp = *e_lst;
	if (!e_lst)
		return ;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		*e_lst = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
}

void	ft_unset(t_env *env, char **arg)
{
	int		i;

	if (!arg[1])
		return ;
	i = 1;
	while (arg[i])
	{
		if (!ft_key_syntax(arg[i]))
			write(1, "not a valid key\n", 24);
		ft_delete_node(&env, arg[i]);
		i++;
	}
	g_stu.ex_stu = EXIT_SUCCESS;
}
