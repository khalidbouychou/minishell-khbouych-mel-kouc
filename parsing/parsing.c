/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/19 20:08:35 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"


// void	check_list_or_arg(t_token *tmp, t_parse **list, int *flag, int *count)
// {
// 	t_parse		*pars;
// 	static int	i;
// 	// char **str;
// 	// *str[] = {">", ">>", "<", "<<"};
// 	// str = {[">"], [">>"], ["<"], ["<<"]};
// 	pars = *list;
// 	if (tmp->operator == 1 && tmp->type != SPACE)
// 		*flag = 0;
// 	printf("i = %d\n", i);
// 	if (*flag == 1)
// 	{
// 		while (pars->next)
// 			pars = pars->next;
// 		if (!pars->arg)
// 			return ;
// 		pars->arg[i] = ft_strdup(tmp->content);
// 		printf("pars->arg[i] = |%s|\n", pars->arg[i]);
// 		if (!tmp->next || (tmp->next && tmp->next->operator == 1 && tmp->next->type != SPACE))
// 		{
// 			pars->arg[i + 1] = NULL;
// 			printf("pars->arg[i + 1] = |%s|\n", pars->arg[i + 1]);
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// 	if (*flag == 0)
// 	{
// 		add_to_list_parser(list, ft_init_parser(tmp));
// 		pars = *list;
// 		while (pars->next)
// 			pars = pars->next;
// 		if (tmp->operator == 0 || (tmp->operator == 1 && tmp->type != PIPE))
// 		{
// 			*count = alloc_arg(tmp->next);
// 			pars->arg = malloc(sizeof(char *) * ((*count) + 1));
// 			if (!pars->arg)
// 				return ;
// 			printf ("count = %d\n", *count);
// 		}
// 		if (tmp->operator == 0)
// 			*flag = 1;
// 	}
// }

// add_to_arg()

// void	push_arg(t_token *tmp, t_parse	*new_p, int *i)
// {
// 	while (tmp)
// 	{
// 		while (tmp && tmp->type != PIPE && (tmp->type == WORD
// 				|| tmp->type == VAR || tmp->type == SPACE))
// 		{
// 			new_p->arg[++(*i)] = ft_strdup(tmp->content);
// 			printf("new_p->arg[%d] = |%s|\n", *i, new_p->arg[*i]);
// 			if (!tmp->next || tmp->next->type == PIPE)
// 				break ;
// 			tmp = tmp->next;
// 		}
// 		if (!tmp->next || tmp->next->type == PIPE)
// 		{
// 			new_p->arg[++(*i)] = NULL;
// 			printf("new_p->arg[%d] = |%s|\n", *i, new_p->arg[*i]);
// 		}
// 		// if (tmp && (tmp->type == INPUT || tmp->type == OUTPUT
// 		// 		|| tmp->type == HERDOC || tmp->type == APPND))
// 		// 	ft_handle_oper(tmp);
// 		if (!tmp || tmp->type == PIPE)
// 			break ;
// 		tmp = tmp->next;
// 	}
// }

// t_parse	*ft_list_parser(t_token *tmp, int count)
// {
// 	t_parse	*new_p;
// 	int		i;

// 	i = -1;
// 	new_p = NULL;
// 	new_p = malloc(sizeof(t_parse));
// 	new_p->arg = malloc(sizeof(char *) * ((count) + 1));
// 	push_arg(tmp, new_p, &i);
// 	// ft_get_type(new_p);
// 	// new_p->path = ft_get_path(env, cmd);
// 	new_p->next = NULL;
// 	return (new_p);
// }

// t_parse	*parser_list(t_token *list_tokens, int *is_alloc, int count)
// {
// 	t_parse	*lst;
// 	t_token	*tmp;
// 	int		i;

// 	tmp = list_tokens;
// 	lst = NULL;
// 	lst = malloc(sizeof(t_parse));
// 	i = 0;
// 	init_parce(lst);
// 	printf("*list->fd_input = %d\n", lst->fd_input);
// 	printf("*list->fd_input = %d\n", lst->fd_output);
// 	printf("*list->fd_input = %d\n", lst->fd_heredoc);
// 	while (tmp)
// 	{
// 		if (*is_alloc == 0)
// 		{
// 			count = alloc_arg(tmp);
// 			printf("count alloc = %d\n", count + 1);
// 			add_to_list_parser(&lst, ft_list_parser(tmp, count));
// 			*is_alloc = 1;
// 		}
// 		if (tmp->type == PIPE)
// 			*is_alloc = 0;
// 		tmp = tmp->next;
// 	}
// 	return (lst);
// }

// void	parser(t_token	*list_tokens)
// {
// 	int		is_alloc;
// 	int		count;

// 	is_alloc = 0;
// 	count = 0;
// 	parser_list(list_tokens, &is_alloc, count);
// }

// t_parse	*parser_list(t_token *list_tokens, int *is_alloc)
// {
// 	t_parse	*lst;
// 	t_token	*tmp;
// 	int		i;
// 	int		flag;

// 	tmp = list_tokens;
// 	lst = NULL;
// 	i = 0;
// 	flag = 0;
// 	// *(pars->arg) = NULL;
// 	while (tmp)
// 	{
// 		check_list_or_arg(tmp, &lst, &flag, is_alloc);
// 		// lst = lst->next;
// 		// printf ("test\n");
// 		tmp = tmp->next;
// 	}
// 	return (lst);
// }

// void	parser(t_token	*list_tokens)
// {
// 	int		is_alloc;

// 	is_alloc = 0;
// 	parser_list(list_tokens, &is_alloc);
// }
