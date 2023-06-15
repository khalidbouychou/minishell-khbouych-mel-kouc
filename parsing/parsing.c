/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/15 18:25:25 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	check_syntax(t_token *list_tokens)
{
	if (!check_operator(list_tokens) || !check_quotes(list_tokens))
	{
		printf("\nsyntax error near unexpected token \n");
	}
	// else
	// 	printf ("\n succese\n");
	// split_operator(list_tokens);
}
// void	check_list_or_arg(t_parse **list, char *str, int *flag)
// {
// 	t_parse	*tmp;

// 	tmp = *list;
// 	if (is_opr(str))
// 		*flag = 0;
// 	if (*flag == 1)
// 	{
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		alloc_arg();
// 		// allocation of arg
// 		*(tmp->arg) = str;
// 		*(tmp->arg) = *(tmp->arg) + 1;
// 	}
// 	if (*flag == 0)
// 	{
// 		add_to_list_parser(list, ft_init_parser(str));
// 		*flag = 1;
// 	}
// }

// int	is_opr(char *str)
// {
// 	if (!ft_strncmp("|", str, 255))
// 		return (0);
// 	else if (!ft_strncmp(">>", str, 255))
// 		return (0);
// 	else if (!ft_strncmp(">", str, 255))
// 		return (0);
// 	else if (!ft_strncmp("<", str, 255))
// 		return (0);
// 	else if (!ft_strncmp("<<", str, 255))
// 		return (0);
// 	return (1);
// }
// int	parser_alloc(char *cmd, int i, t_parse **list, int *flag)
// {
// 	int		count;
// 	int		init;
// 	char	*str;

// 	count = 0;
// 	init = i;
// 	if ((cmd[i] == '>' && cmd[i + 1] == '>') || (cmd[i] == '<'
// 			&& cmd[i + 1] == '<'))
// 	{
// 		count = 2;
// 		i = i + count;
// 	}
// 	else if (cmd[i] == '|' || cmd[i] == ' ' || cmd[i] == '>' || cmd[i] == '<')
// 	{
// 		count = 1;
// 		i = i + count;
// 	}
// 	else if ((cmd[i] == '\"' || cmd[i] == '\''))
// 		count = ft_qoutes(cmd, &i, init);
// 	else
// 		count = ft_word(cmd, &i, init);
// 	str = ft_substr(cmd, i, count);
// 	check_list_or_arg(list, str, flag);
// 	return (i);
// }

// void	*parser_list(char *cmd, t_token	*list_tokens)
// {
// 	t_parse	*lst;
// 	t_token	*tmp;
// 	int		i;
// 	int		flag;

// 	tmp = list_tokens;
// 	lst = NULL;
// 	i = 0;
// 	flag = 0;
// 	while (cmd[i] && cmd[i] == 32)
// 		i++;
// 	while (cmd[i])
// 	{
// 		if (cmd[i] == '|')
// 			i = parser_alloc(cmd, i, &lst, &flag);
// 		else if (cmd[i] == ' ')
// 			i = parser_alloc(cmd, i, &lst, &flag);
// 		else if (cmd[i] == '>')
// 			i = parser_alloc(cmd, i, &lst, &flag);
// 		else if (cmd[i] == '<')
// 			i = parser_alloc(cmd, i, &lst, &flag);
// 		else
// 			i = parser_alloc(cmd, i, &lst, &flag);
// 	}
// 	return (lst);
// }
t_parse	*ft_last_parser(t_parse *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
t_parse	*ft_init_parser(t_token *tmp)
{
	t_parse	*new_p;

	new_p = NULL;
	new_p = malloc(sizeof(t_parse));
	new_p->content = tmp->content;
	// ft_get_type(new_p);
	// new_p->path = ft_get_path(env, cmd);
	new_p->next = NULL;
	return (new_p);
}
void	add_to_list_parser(t_parse **lst_tok, t_parse *newtok)
{
	t_parse	*last;

	if (*lst_tok == NULL)
		*lst_tok = newtok;
	else
	{
		last = ft_last_parser(*lst_tok);
		last->next = newtok;
	}
}
int	alloc_arg(t_token *tmp)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	while (tmp)
	{
		printf("content = %s\n", tmp->content);
		while (tmp && tmp->type == SPACE)
		{
			if (!tmp->next)
			{
				flag = 1;
				break ;
			}
			else if (tmp->next && tmp->next->type == SPACE)
				tmp = tmp->next;
			else
				break ;
		}
		if (flag == 1 || (tmp->operator == 1 && tmp->type != SPACE))
			break ;
		size++;
		printf("alloc\n");
		tmp = tmp->next;
	}
	return (size);
}
void	check_list_or_arg(t_token *tmp, t_parse **list, int *flag)
{
	t_parse	*pars;
	int		is_alloc;

	printf ("hello\n");
	is_alloc = 0;
	pars = *list;
	// if (pars)
	// 	printf("pars = %s\n", pars->content);
	if (tmp->operator == 1 && tmp->type != SPACE)
		*flag = 0;
	if (*flag == 1)
	{
		while (pars->next)
			pars = pars->next;
		printf ("world\n");
		*(pars->arg) = tmp->content;
		printf ("test\n");
		*(pars->arg) = *(pars->arg) + 1;
	}
	if (*flag == 0)
	{
		add_to_list_parser(list, ft_init_parser(tmp));
		if (tmp->operator == 0)
			alloc_arg(tmp->next);
		int count = alloc_arg(tmp->next);
		printf ("count = %d\n", count);
		*flag = 1;
	}
}

t_parse	*parser_list(t_token *list_tokens)
{
	t_parse	*lst;
	t_token	*tmp;
	int		i;
	int		flag;

	tmp = list_tokens;
	lst = NULL;
	i = 0;
	flag = 0;
	while (tmp)
	{
		// echo   "hello" 
		// |    ls
		while ((tmp && i == 1 && flag == 1 && tmp->type == SPACE)
			|| (tmp && tmp->next && flag == 0 && tmp->type == SPACE))
			tmp = tmp->next;
		check_list_or_arg(tmp, &lst, &flag);
		tmp = tmp->next;
		if (i == 0)
			i++;
	}
	return (lst);
}
void	parser(t_token	*list_tokens)
{
	check_syntax(list_tokens);
	parser_list(list_tokens);
}
