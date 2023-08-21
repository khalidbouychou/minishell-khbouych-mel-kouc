/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 01:45:39 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	push_arg(t_token *tmp, t_parse *new_p, int *i, t_env *env)
{
	while (tmp)
	{
		while (tmp && tmp->type != PIPE && (tmp->type == WORD
				|| tmp->type == VAR || tmp->type == SPC))
		{
			if (tmp->content && *tmp->content)
				new_p->arg[++(*i)] = ft_strdup(tmp->content);
			if (*i == 0 && !compare_path(tmp->content))
				new_p->path = ft_get_path(env, new_p->arg[0]);
			if (!tmp->next || tmp->next->type == PIPE)
				break ;
			tmp = tmp->next;
		}
		ft_searsh_herdoc(tmp, new_p, env);
		if (!tmp || tmp->type == PIPE)
		{
			g_v.sig = 1;
			break ;
		}
		if (g_v.sig == -1)
			break ;
		tmp = tmp->next;
	}
}

t_parse	*ft_list_parser(t_token *tmp, int count, t_env *env)
{
	t_parse	*new_p;
	int		i;

	i = -1;
	new_p = malloc(sizeof(t_parse));
	init_struct_parce(new_p);
	new_p->arg = malloc(sizeof(char *) * (count + 1));
	if (!new_p->arg)
		return (NULL);
	new_p->path = NULL;
	push_arg(tmp, new_p, &i, env);
	i++;
	new_p->arg[i] = NULL;
	new_p->next = NULL;
	return (new_p);
}

int	redirection(t_token	*list_tokens, t_parse *list_pars)
{
	t_token	*tmp_tok;
	t_parse	*tmp_pars;
	int		_flag;

	_flag = 0;
	tmp_tok = list_tokens;
	tmp_pars = list_pars;
	while (tmp_tok)
	{
		if (tmp_tok->type == PIPE)
			_flag = 0;
		if (tmp_tok && _flag == 0 && (tmp_tok->type == INPUT
				|| tmp_tok->type == OUTPUT || tmp_tok->type == APPND))
			tmp_tok = ft_handle_oper(tmp_tok, tmp_pars, &_flag);
		else if (tmp_tok->type == PIPE)
			tmp_pars = tmp_pars->next;
		if (tmp_tok)
			tmp_tok = tmp_tok->next;
	}
	return (1);
}

t_parse	*parser_list(t_token *list_tokens, int *is_alloc, t_env *env)
{
	t_parse	*lst;
	t_token	*tmp;
	int		i;
	int		count;

	count = 0;
	tmp = list_tokens;
	lst = NULL;
	i = 0;
	while (tmp)
	{
		if (*is_alloc == 0)
		{
			count = alloc_arg(tmp);
			add_to_list_parser(&lst, ft_list_parser(tmp, count, env));
			*is_alloc = 1;
		}
		if (tmp->type == PIPE && g_v.sig == 1)
			*is_alloc = 0;
		tmp = tmp->next;
	}
	return (lst);
}

t_parse	*parser(t_token	*list_tokens, t_env *env)
{
	int		is_alloc;
	t_parse	*list_pars;

	is_alloc = 0;
	list_pars = parser_list(list_tokens, &is_alloc, env);
	if (g_v.sig == 1)
		redirection(list_tokens, list_pars);
	g_v.sig = 1;
	return (list_pars);
}
