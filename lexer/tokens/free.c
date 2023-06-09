/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:26 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/22 17:12:23 by mel-kouc         ###   ########.fr       */
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
		free (tmp);
		tmp = next;
	}
	env = NULL;
}
