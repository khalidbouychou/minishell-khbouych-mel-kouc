/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/28 21:48:35 by khbouych         ###   ########.fr       */
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
    APPND,
    HERDOC,
    LRED,
    OUTPUT,
    INPUT,
    SPACE,
    VAR
};
typedef struct s_lexer
{
    char *content;
    enum token_e type;
    char *path;
    t_lexer *next;
}t_lexer;

/*******************/

int	ft_strncmp(const char *str1, const char *str2, int n);

#endif