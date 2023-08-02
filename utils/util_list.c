/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:37:03 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/02 12:12:13 by mel-kouc         ###   ########.fr       */
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

t_env	*add_env(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_if_not_found(t_env **head, int i)
{
	char	*key;
	char	*value;

	while (++i < 4)
	{
		// printf("%d\n", i);
		if (i == 0)
		{
			key = ft_strdup("PWD");
			value = ft_strdup("/Users/mel-kouc/Desktop/minishell-khbouych-mel-kouc");
		}
		else if (i == 1)
		{
			key = ft_strdup("SHLVL");
			value = ft_strdup("1");
		}
		else if (i == 2)
		{
			key = ft_strdup("_");
			value = ft_strdup("/usr/bin/env");
		}
		else if (i == 3)
		{
			key = ft_strdup("PATH");
			value = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
		}
		ft_lst_addback(head, add_env(key, value));
	}
}

t_env	*env_list(char **env)
{
	int		i;
	t_env	*head;
	t_env	*old;

	head = NULL;
	i = -1;
	head = NULL;
	g_stu.current_pwd = getcwd(NULL, 0);
	if (*env == NULL)
		add_if_not_found(&head, i);
	else
	{
		i = 0;
		while (env[i])
			ft_lst_addback(&head, ft_lstnew(env[i++]));
	}
	old = ft_getenv_node(head, "OLDPWD");
	if (!old)
		ft_lst_addback(&head, ft_add_env("OLDPWD", NULL));
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
