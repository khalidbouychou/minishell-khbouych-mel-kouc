/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/03 21:19:05 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	check_spases(t_token *tmp)
{
	while (!ft_strncmp(tmp->content, " ", 1))
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			printf("\nsyntax error near unexpected token 4\n");
			return ;
		}
	}
}

void	check_pipe(t_token	*list_tokens)
{
	t_token	*tmp;

	tmp = list_tokens;
	if (!tmp)
		return ;
	if (!ft_strncmp((*tmp).content, "|", 1))
		printf("\nsyntax error near unexpected token 1\n");
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, "|", 1))
		{
			if (tmp->next == NULL)
				printf("\nsyntax error near unexpected token 2\n");
			else if (!ft_strncmp(tmp->next->content, "|", 1))
				printf("\nsyntax error near unexpected token 3\n");
			else if (!ft_strncmp(tmp->next->content, " ", 1))
				check_spases(tmp->next);
		}
		tmp = tmp->next;
	}
}

void	test(t_token	*list_tokens)
{
	t_token	*tmp;

	tmp = list_tokens;
	while (tmp)
	{
		if (tmp->operator == 1 && tmp->type != SPACE)
		{
			if (tmp->next == NULL)
				printf("\nsyntax error near unexpected token 2\n");
			else if (!ft_strncmp(tmp->next->content, " ", 1))
				check_spases(tmp->next);
		}
		tmp = tmp->next;
	}
}

void	parser(t_token	*list_tokens)
{
	check_pipe(list_tokens);
	// test(list_tokens);
	// check_quotes(list_tokens);
}
