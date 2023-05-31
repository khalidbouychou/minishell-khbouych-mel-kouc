/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/29 15:19:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

static char *ft_get_relativepath(char *path , char *cmd)
{
    char **sp;
    sp = ft_split(path,':');
    path = ft_substr(sp[1],4,4);
    path = ft_strjoin(path,"/");
    path = ft_strjoin(path,cmd);
    return path;
}
static char *ft_get_path(t_env *env ,char *cmd)
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
static t_token *ft_init_token(char *cmd , t_env *env)
{
    t_token *tok;
    tok = malloc(sizeof(t_token));
    tok->content = cmd;
    tok->type = WORD;
    tok->path = ft_get_path(env,cmd);
    tok->next = NULL;
    return tok;
}

t_token *ft_new_token(char *cmd , t_env *env)
{
    t_token	*tok;
    tok = ft_init_token(cmd,env);
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
    if(tok->type != WORD && tok->type != VAR)
        tok->operator = 1;
    else
        tok->operator = 0;
	return (tok);
}

void ft_add_to_list_tokens(t_token **lst_tok , t_token *newtok)
{
    t_token *tmp;
    if(!(*lst_tok))
    {
        (*lst_tok) = newtok;
        return;
    }
    tmp = (*lst_tok);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = newtok;
}
