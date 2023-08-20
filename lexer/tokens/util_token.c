/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:03:22 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/20 03:44:00 by khbouych         ###   ########.fr       */
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

void	check_herdoc_quotes(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->type == HERDOC)
		{
			tmp = tmp->next;
			while (tmp->type == SPC || tmp->type == _TAB)
				tmp = tmp->next;
			if (tmp->next && tmp->next->type != SPC
				&& tmp->next->type != _TAB
				&& (!ft_strcmp(tmp->content, "''")
					|| !ft_strcmp(tmp->content, "\"\"")))
				tmp->_flag = 1;
			else if (tmp->content[0] == '\'' || tmp->content[0] == '"')
				tmp->_flag = 1;
			else if (tmp->next && (!ft_strcmp(tmp->next->content, "''")
					|| !ft_strcmp(tmp->next->content, "\"\"")))
				tmp->_flag = 1;
		}
		tmp = tmp->next;
	}
}

void	ft_get_type(t_token *tok)
{
	tok->type = WORD;
	if (ft_strchr(tok->content, '$') != -1
		&& ((ft_strchr(tok->content, '\'') == -1)
			|| (ft_strchr(tok->content, '"') < ft_strchr(tok->content, '\'')
				&& ft_strchr(tok->content, '"') != -1)))
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
		tok->type = SPC;
	else if ('	' == tok->content[0])
		tok->type = _TAB;
	if (tok->type != WORD)
		tok->path = NULL;
	ft_set_oper(tok);
}

t_token	*ft_init_token(char *cmd, int i, int count)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	tok->content = NULL;
	tok->next = NULL;
	tok->prev = NULL;
	tok->_flag = 0;
	tok->content = ft_substr(cmd, i, count);
	ft_get_type(tok);
	return (tok);
}
