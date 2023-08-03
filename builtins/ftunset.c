/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftunset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:52 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/03 01:25:16 by mel-kouc         ###   ########.fr       */
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
	if (!ft_strcmp(tmp->key, key))
	{
		*e_lst = tmp->next;
		(*e_lst)->next = tmp->next->next;
		(*e_lst)->prev = NULL;
		tmp->next = NULL;
		// printf("list E_list --> %s = %s \n",(*e_lst)->key, (*e_lst)->value);
		// tmp->next = (*e_lst)->next;
		// (*e_lst)->prev = tmp->prev;
		// if (tmp->next != NULL)
		// 	tmp->next->prev = tmp->prev;
		// if (tmp->prev != NULL)
		// 	tmp->prev->next = tmp->next;
		free (tmp);
		// ft_print_env(*e_lst);
	}

	// else
	// {
	// 	while (tmp)
	// 	{
	// 		if (!ft_strcmp(key, tmp->key))
	// 			break ;
	// 		tmp = tmp->next;
	// 	}
	// 	if (!tmp)
	// 		return ;
	// 	if (tmp->prev)
	// 	{
	// 		printf("1 --> %s = %s \n",tmp->key,tmp->value);
	// 		tmp->prev->next = tmp->next;
	// 	}
	// 	else
	// 	{
	// 		printf("2 --> %s = %s \n",tmp->key,tmp->value);
	// 		*e_lst = tmp->next;
	// 		printf("list --> %s = %s \n",(*e_lst)->key, (*e_lst)->value);
	// 	}
	// 	if (tmp->next)
	// 	{
	// 		printf("3 --> %s = %s \n",tmp->key,tmp->value);
			
	// 		tmp->next->prev = tmp->prev;
	// 	}
	// }
	// free(tmp->key);
	// free(tmp->value);
	// free (tmp);
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
