/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/15 15:31:50 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

// void	check_syntax(t_token *list_tokens)
// {
// 	if (!check_operator(list_tokens) || !check_quotes(list_tokens))
// 	{
// 		printf("\nsyntax error near unexpected token \n");
// 	}
	// else
	// 	printf ("\n succese\n");
	// split_operator(list_tokens);
// }

///////////////////// this code is to maintene parser
// t_parse	*ft_last_parser(t_parse *lst)
// {
// 	if (!lst)
// 		return (0);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }
// t_parse	*ft_init_parser(t_token *tmp)
// {
// 	t_parse	*new_p;

// 	new_p = NULL;
// 	new_p = malloc(sizeof(t_parse));
// 	new_p->content = tmp->content;
// 	printf("new_p = |%s|\n", new_p->content);
// 	// ft_get_type(new_p);
// 	// new_p->path = ft_get_path(env, cmd);
// 	new_p->next = NULL;
// 	return (new_p);
// }
// void	add_to_list_parser(t_parse **lst_tok, t_parse *newtok)
// {
// 	t_parse	*last;

// 	if (*lst_tok == NULL)
// 		*lst_tok = newtok;
// 	else
// 	{
// 		last = ft_last_parser(*lst_tok);
// 		last->next = newtok;
// 	}
// }
// int	alloc_arg(t_token *tmp)
// {
// 	int	size;
// 	int	flag;

// 	size = 0;
// 	flag = 0;
// 	while (tmp)
// 	{
// 		if (tmp->operator == 1 && tmp->type != SPACE)
// 			break ;
// 		size++;
// 		tmp = tmp->next;
// 	}
// 	return (size);
// }

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
// void	check_parce_list(t_token *tmp, t_parse **list, int *flag, int *count)
// {
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
// 		check_parce_list(tmp, &lst, &flag, is_alloc);
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
