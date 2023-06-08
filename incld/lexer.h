/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/04 13:06:27 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../incld/minishell.h"
# include "../incld/token.h"
/*******************/
void    ft_expander(t_token *tok, t_env *env);

#endif