/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:03:22 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/21 09:46:25 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

int	ft_qoutes(char *cmd, int *i, int init)
{
	int	count;

	count = 0;
	if (cmd[*i] == '\"' )
	{
		*i = *i + 1;
		while (cmd[*i] != '\"' && cmd[*i])
			*i = *i + 1;
		*i = *i + 1;
		count = *i - init;
	}
	else if (cmd[*i] == '\'')
	{
		*i = *i + 1;
		while (cmd[*i] != '\'' && cmd[*i])
			*i = *i + 1;
		*i = *i + 1;
		count = *i - init;
	}
	return (count);
}

int	ft_word(char *cmd, int *i, int init)
{
	int	count;

	count = 0;
	while (cmd[*i] && (cmd[*i] != '|' && cmd[*i] != ' ' \
		&& cmd[*i] != '>' && cmd[*i] != '<'
			&& cmd[*i] != '\'' && cmd[*i] != '"'
			&& cmd[*i] != '	'))
		*i = *i + 1;
	count = *i - init;
	return (count);
}

char	*ft_get_path(t_env *env, t_token *tok)
{
	char	*p;
	t_env	*tmp;

	p = NULL;
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "PATH", 4) == 0)
		{
			p = tmp->value;
			break ;
		}
		tmp = tmp->next;
	}
	return (ft_check_if_cmd_valid(ft_split(p, ':'), tok));
}

void	ft_get_type(t_token *tok)
{
	tok->type = WORD;
	if ('$' == tok->content[0])
		tok->type = VAR;
	else if ('>' == tok->content[0] && '>' == tok->content[1])
		tok->type = APPND;
	else if ('<' == tok->content[0] && '<' == tok->content[1])
		tok->type = HERDOC;
	else if ('>' == tok->content[0])
		tok->type = OUTPUT;
	else if ('<' == tok->content[0])
		tok->type = INPUT;
	else if ('|' == tok->content[0])
		tok->type = PIPE;
	else if (32 == tok->content[0])
		tok->type = SPACE;
	else if ('	' == tok->content[0])
		tok->type = TAB;
	if (tok->type != WORD)
		tok->path = NULL;
	if (tok->type != WORD && tok->type != VAR)
		tok->operator = 1;
	else
		tok->operator = 0;
}

t_token	*ft_init_token(char *cmd, int i, int count, t_env *env)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	tok->content = ft_substr(cmd, i, count);
	ft_get_type(tok);
	tok->path = ft_get_path(env, tok);
	tok->next = NULL;
	tok->prev = NULL;
	return (tok);
}
