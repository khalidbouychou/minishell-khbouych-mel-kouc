/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:12:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/13 22:52:09 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ptr_is_opr(t_token *ptr, t_env *env, t_token *dolar)
{
	if (ptr && (ptr->type == OUTPUT || ptr->type == INPUT
			|| ptr->type == APPND)
		&& !ft_getenv_node(env, dolar->content))
		g_stu.flag = 1;
}

void	ft_expander(t_token *tok, t_env *env)
{
	char			*res;
	t_token			*tmp;
	t_token			*ptr;
	t_token			*dolar;

	tmp = tok;
	while (tmp)
	{
		if (tmp->type == VAR)
		{
			dolar = tmp;
			ptr = tmp->prev;
			while (ptr && (ptr->type == SPC || ptr->type == _TAB))
				ptr = ptr->prev;
			if ((ptr && (ptr->content[0] != '\0' && ptr->type != HERDOC))
				|| !ptr)
			{
				res = ft_strjoin(res, ft_expandhelp(tmp->content, env));
				tmp->content = res;
			}
			// ptr_is_opr(ptr, env, dolar);
			if (ptr && (ptr->type == OUTPUT || ptr->type == INPUT
					|| ptr->type == APPND)
				&& !ft_getenv_node(env, dolar->content))
				g_stu.flag = 1;
		}
		tmp = tmp->next;
	}
}
