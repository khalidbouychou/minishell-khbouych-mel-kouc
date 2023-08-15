/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:12:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/16 00:02:42 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

// void	ptr_is_opr(t_token *ptr, t_env *env, t_token *dolar)
// {
// 	if (ptr && (ptr->type == OUTPUT || ptr->type == INPUT
// 			|| ptr->type == APPND)
// 		&& !ft_getenv_node(env, dolar->content))
// 		g_stu.flag = 1;
// }
void	expand_redir(t_token *tmp, t_env *env)
{
	t_token	*dolar;
	t_token	*ptr;

	if (tmp->type == VAR)
	{
		dolar = tmp;
		ptr = tmp->prev;
		while (ptr && (ptr->type == SPC || ptr->type == _TAB))
			ptr = ptr->prev;
		if ((ptr && (ptr->content[0] != '\0' && ptr->type != HERDOC))
			|| !ptr)
			tmp->content = ft_expandhelp(tmp->content, env);
		if (ptr && (ptr->type == OUTPUT || ptr->type == INPUT
				|| ptr->type == APPND)
			&& !ft_getenv_node(env, dolar->content))
			g_stu.flag = 1;
	}
}

void	ft_expander(t_token *tok, t_env *env)
{
	t_token	*tmp;

	tmp = tok;
	// res = NULL;
	while (tmp)
	{
		expand_redir(tmp, env);
		// if (tmp->type == VAR)
		// {
		// 	dolar = tmp;
		// 	ptr = tmp->prev;
		// 	while (ptr && (ptr->type == SPC || ptr->type == _TAB))
		// 		ptr = ptr->prev;
		// 	if ((ptr && (ptr->content[0] != '\0' && ptr->type != HERDOC))
		// 		|| !ptr)
		// 		tmp->content = ft_expandhelp(tmp->content, env);
		// 	// ptr_is_opr(tmp, ptr, env, dolar);
		// 	if (ptr && (ptr->type == OUTPUT || ptr->type == INPUT
		// 			|| ptr->type == APPND)
		// 		&& !ft_getenv_node(env, dolar->content))
		// 		g_stu.flag = 1;
		// }
		tmp = tmp->next;
	}
}
