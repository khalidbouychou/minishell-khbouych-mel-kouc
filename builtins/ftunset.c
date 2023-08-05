/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftunset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/03 15:40:29 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_key_syntax(char *key)
{
	int	i;
	if (key && !ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	if (key && !ft_isalnum(key[ft_strlen(key) - 1]) && ft_strlen(key) > 1)
		return (0);
	i = 1;
	while (key && key[i])
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
	t_env	*prev;
	t_env	*next;

	tmp = ft_getenv_node(*e_lst, key);
	if (!tmp)
		return ;
	prev = tmp->prev;
	next = tmp->next;
	if (!prev)
	{
		*e_lst = next;
		if (next)
			next->prev = NULL;
	}
	else
	{
		prev->next = next;
		if (next)
			next->prev = prev;
	}
	free(tmp->key);
	free(tmp->value);
	free (tmp);
}

void	ft_unset(t_env **env, char **arg)
{
	int		i;

	if (!arg[1])
		return ;
	i = 1;
	while (arg[i])
	{
		if (!ft_key_syntax(arg[i]))
			ft_putendl_fd("not a valid key", 2);
		else
			ft_delete_node(env, arg[i]);
		i++;
	}
	g_stu.ex_stu = EXIT_SUCCESS;
}
