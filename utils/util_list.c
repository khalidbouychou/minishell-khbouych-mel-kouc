/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:37:03 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/24 21:18:47 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

t_env	*ft_lstnew(char *env)
{
	t_env	*new_node;
	int		equal;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	equal = ft_strchr(env, '=');
	if (equal != -1)
	{
		new_node->key = ft_substr(env, 0, equal);
		new_node->value = ft_substr(env, equal + 1, ft_strlen(env) - equal);
	}
	else
	{
		new_node->key = ft_substr(env, 0, ft_strlen(env));
		new_node->value = NULL;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_env	*ft_lstlast(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lst_addback(t_env **head, t_env *new)
{
	t_env	*last;

	if (!head || !new)
		return ;
	else if (*head == 0)
		*head = new;
	else
	{
		last = ft_lstlast(*head);
		last->next = new;
		new->prev = last;
	}
}

t_env	*env_list(char **env)
{
	int		i;
	t_env	*head;

	i = 0;
	head = NULL;
	while (env[i])
	{
		ft_lst_addback(&head, ft_lstnew(env[i]));
		i++;
	}
	return (head);
}

t_token	*ft_listlast(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
