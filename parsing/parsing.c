/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/26 01:23:22 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	push_arg(t_token *tmp, t_parse *new_p, int *i)
{
	while (tmp)
	{
		while (tmp && tmp->type != PIPE && (tmp->type == WORD
				|| tmp->type == VAR || tmp->type == SPACE))
		{
			new_p->arg[++(*i)] = ft_strdup(tmp->content);
			// printf("new_p->arg[%d] = |%s|\n", *i, new_p->arg[*i]);
			if (!tmp->next || tmp->next->type == PIPE)
				break ;
			tmp = tmp->next;
		}
		if (!tmp->next || (tmp->next && tmp->next->type == PIPE))
		{
			new_p->arg[++(*i)] = NULL;
			// printf("new_p->arg[%d] = |%s|\n", *i, new_p->arg[*i]);
		}
		ft_searsh_herdoc(tmp, new_p);
		if (!tmp || tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
}

t_parse	*ft_list_parser(t_token *tmp, int count)
{
	t_parse	*new_p;
	int		i;

	i = -1;
	(void)tmp;
	new_p = malloc(sizeof(t_parse));
	init_struct_parce(new_p);
	// printf("*list->fd_input = %d\n", lst->fd_input);
	// printf("*list->fd_input = %d\n", lst->fd_output);
	// printf("*list->fd_input = %d\n", lst->fd_heredoc);
	// printf("\nparser count + 1 = | %d |\n", count + 1);
	new_p->arg = malloc(sizeof(char *) * (count + 1));
	push_arg(tmp, new_p, &i);
	// ft_get_type(new_p);
	// new_p->path = ft_get_path(env, cmd);
	new_p->next = NULL;
	return (new_p);
}

t_parse	*parser_list(t_token *list_tokens, int *is_alloc)
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
			add_to_list_parser(&lst, ft_list_parser(tmp, count));
			*is_alloc = 1;
		}
		if (tmp->type == PIPE)
			*is_alloc = 0;
		tmp = tmp->next;
	}
	return (lst);
}
t_parse	*parser(t_token	*list_tokens)
{
	int		is_alloc;
	t_parse	*list_pars;
	t_token	*tmp_tok;
	t_parse	*tmp_pars;

	is_alloc = 0;
	list_pars = parser_list(list_tokens, &is_alloc);
	tmp_tok = list_tokens;
	tmp_pars = list_pars;
	while (tmp_tok)
	{
		if (tmp_tok->type != PIPE)
		{
			// printf("\ntmp->content = %s\n", tmp_tok->content);
			if (tmp_tok && (tmp_tok->type == INPUT || tmp_tok->type == OUTPUT
					|| tmp_tok->type == APPND))
				tmp_tok = ft_handle_oper(tmp_tok, tmp_pars);
		}
		else
			tmp_pars = tmp_pars->next;
		tmp_tok = tmp_tok->next;
	}
	// printf("\n***** fd int = %d *****\n", tmp_pars->fd_input);
	// printf("\n***** fd out = %d *****\n", tmp_pars->fd_output);
	// execute_main(list_pars);
	return (list_pars);
}
