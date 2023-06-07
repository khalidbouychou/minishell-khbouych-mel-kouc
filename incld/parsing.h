/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/07 20:31:22 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../incld/token.h"

void	parser(t_token	*list_tokens);
int		check_operator(t_token	*list_tokens);
int		check_pipe(t_token	*list_tokens);
int		check_spases(t_token *tmp);
int		check_quotes(t_token *list_tokens);
void	split_operator(t_token *list_tokens);

#endif