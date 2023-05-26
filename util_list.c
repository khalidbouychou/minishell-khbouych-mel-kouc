/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:37:03 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/26 11:44:07 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

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
		new_node->next = NULL;
	}
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
