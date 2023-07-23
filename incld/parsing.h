/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/23 22:15:45 by mel-kouc         ###   ########.fr       */
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
	int				fd_output;
	char			*f_name;
	// variable to specify whitsh redirection we have
	// int				fd_append;
	// int				fd_herdoc;
	// char			*name_inp;
	// char			*name_outp;
	// char			*name_append;
	// char			*name_herdoc;
	char			**arg;
	struct s_parse	*next;
	// t_token			*ptr;
}	t_parse;

// t_parse	*parser_list(t_token *list_tokens); 
void	parser(t_token	*list_tokens);
t_parse	*ft_last_parser(t_parse *lst);
int		alloc_arg(t_token *tmp);
void	init_struct_parce(t_parse *new_p);
void	add_to_list_parser(t_parse **lst_tok, t_parse *newtok);
t_token	*ft_handle_oper(t_token *tmp, t_parse *new_p);
void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p);
// int		check_pipe(t_token	*list_tokens);
// int		check_spases(t_token *tmp);
// void	split_operator(t_token *list_tokens);

#endif