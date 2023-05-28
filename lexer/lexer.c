/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:22:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/28 21:48:13 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

// lexer and tokenizer the coomand line

char *ft_get_relativepath(char *path , char *cmd)
{
    char **sp;
    sp = ft_split(path,':');
    path = ft_substr(sp[1],4,4);
    path = ft_strjoin(path,"/");
    path = ft_strjoin(path,cmd);
    return path;
}
char *ft_get_path(t_env *env ,char *cmd)
{
    char *path = NULL;
    t_env *tmp;
    tmp = env;
    while (tmp)
    {
        if(ft_strncmp(tmp->key,"PATH",4) == 0)
        {
            path = tmp->value;
            break;
        }
        tmp = tmp->next;
    }
    path = ft_get_relativepath(path,cmd);
    return path;
}
t_lexer *ft_grep_token(char *cmd , t_env *env)
{
    t_lexer *tok;
    tok = malloc(sizeof(t_lexer));
    tok->content = cmd;
    tok->type = WORD;
    tok->path = ft_get_path(env,cmd);
    return tok;
}
t_lexer *ft_create_token(char *cmd , t_env *env)
{
    t_lexer	*tok;
    tok = malloc(sizeof(t_lexer));
    tok = ft_grep_token(cmd,env);
    if (!ft_strncmp("|", cmd, 255))
		tok->type = PIPE;
	else if (!ft_strncmp(">>", cmd, 255))
		tok->type = APPND;
	else if (!ft_strncmp(">", cmd, 255))
		tok->type = OUTPUT;
	else if (!ft_strncmp("<", cmd, 255))
		tok->type = INPUT;
	else if (!ft_strncmp("<<", cmd, 255))
		tok->type = HERDOC;
    else if (!ft_strncmp("$", cmd, 255))
		tok->type = VAR;
    if (tok->type != WORD)
        tok->path = NULL;
	return (tok);
}

void ft_add_to_list_tokens(t_lexer **lst_tok , t_lexer *newtok)
{
    t_lexer *tmp;
    tmp = (*lst_tok);
    while (tmp)
    {
        tmp = tmp.
    }
    
}
