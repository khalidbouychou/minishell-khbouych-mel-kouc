/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/24 13:44:44 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../incld/token.h"

typedef struct s_parse
{
	char			*content;
	struct s_parse	*next;
	char			**arg;
	t_token			*ptr;
}	t_parse;

// t_parse	*parser_list(t_token *list_tokens);
void	parser(t_token	*list_tokens);
// int		check_pipe(t_token	*list_tokens);
// int		check_spases(t_token *tmp);
// void	split_operator(t_token *list_tokens);

#endif