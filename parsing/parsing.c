/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/07 23:22:16 by mel-kouc         ###   ########.fr       */
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

void	parser(t_token	*list_tokens)
{
	check_syntax(list_tokens);
}
