/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:26 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/21 21:50:48 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

void	free_token_list(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;

	tmp = *lst;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free (ptr);
	}
}

void	free_env_list(t_env *env)
{
	t_env	*tmp;
	t_env	*ptr;

	tmp = env;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free (ptr);
	}
}
