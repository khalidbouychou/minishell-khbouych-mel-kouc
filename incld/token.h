/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:21 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/29 15:11:58 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

enum token_enum
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
/******************************************************************/
typedef struct s_token
{
    char *content;
    enum token_enum type;
    char *path;
    int operator;
   struct s_token *next;
}t_token;

/************************************************************/
int	ft_strncmp(const char *str1, const char *str2, int n);
void ft_add_to_list_tokens(t_token **lst_tok , t_token *newtok);

#endif