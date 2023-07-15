/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/15 10:42:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../incld/token.h"

// typedef struct s_parse
// {
// 	char			*content;
// 	struct s_parse	*next;
// 	t_token			*ptr;
// 	char			**arg;
// }	t_parse;

typedef struct s_parse
{
	// char			cmd;
	int				fd_input;
	int				fd_in_heredoc;
	int				fd_output;
	char			*name;
	char			**arg;
	// t_token			*ptr;
}	t_parse;

// example : < out << here cat
// typedef struct s_parse
// {
// 	char			cmd;// not obligate
// 	int				fd_input;// -1
// 	int				fd_in_heredoc//4
// 	int				fd_output;// 3
// 	char			*name; //name of file -> : out3
// 	struct s_parse	*next;
// 	char			**arg; //arg[0] = ls| args[1] = -l | args[2] = NULL
// 	t_token			*ptr;
// }	t_parse;

//--------------
//args[0] = wc | args[1] = -l | args[2]= NULL
//fd_in = 4 
// t_parse	*parser_list(t_token *list_tokens);
void	parser(t_token	*list_tokens);
// int		check_pipe(t_token	*list_tokens);
// int		check_spases(t_token *tmp);
// void	split_operator(t_token *list_tokens);

#endif