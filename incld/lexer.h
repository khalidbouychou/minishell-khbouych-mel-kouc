/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/28 15:09:12 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_H
# define LEXER_H

enum token_e
{
    WORD,
    PIPE,
    DQ,
    SQ,
    RRED,
    APPND,
    LRED,
    ORED,
    IRED,
    SPACE,
    HERDOC,
    VAR
};
typedef struct s_lexer
{
    char *content;
    enum token_e type;
    char *path;
}t_lexer;

#endif