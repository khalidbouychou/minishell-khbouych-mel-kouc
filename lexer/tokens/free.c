/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:26 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/21 03:47:26 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

void	free_token_list(t_token **lst)
{
	t_token	*tmp;
	t_token	*next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->content);
		free (tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	free_env_list(t_env *env)
{
	t_env	*tmp;
	t_env	*next;

	tmp = env;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free (tmp);
		tmp = next;
	}
	env = NULL;
}

void	free_char_double(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_parser_list(t_parse **list)
{
	t_parse	*tmp;
	t_parse	*next;

	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->path);
		free_char_double(tmp->arg);
		free (tmp);
		tmp = next;
	}
	*list = NULL;
}

void	free_pipe(t_pipe *pipe)
{
	t_pipe	*tmp;
	t_pipe	*next;

	tmp = pipe;
	while (tmp)
	{
		next = tmp->next;
		free (tmp);
		tmp = next;
	}
	pipe = NULL;
}
