/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:26 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/30 18:29:54 by mel-kouc         ###   ########.fr       */
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
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
