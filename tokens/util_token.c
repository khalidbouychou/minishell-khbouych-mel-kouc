/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:03:22 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/03 17:00:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

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
		&& cmd[*i] != '>' && cmd[*i] != '<'))
		*i = *i + 1;
	count = *i - init;
	return (count);
}

char	*ft_get_path(t_env *env, char *cmd)
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
	return (ft_check_if_cmd_valid(ft_split(p, ':'), cmd));
}

void	ft_get_type(t_token *tok)
{
	tok->type = WORD;
	if (!ft_strncmp("|", tok->content, 255))
		tok->type = PIPE;
	else if (!ft_strncmp(">>", tok->content, 255))
		tok->type = APPND;
	else if (!ft_strncmp(">", tok->content, 255))
		tok->type = OUTPUT;
	else if (!ft_strncmp("<", tok->content, 255))
		tok->type = INPUT;
	else if (!ft_strncmp("<<", tok->content, 255))
		tok->type = HERDOC;
	else if (!ft_strncmp("$", tok->content, 255))
		tok->type = VAR;
	else if (!ft_strncmp(" ", tok->content, 255))
		tok->type = SPACE;
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

	tok = NULL;
	tok = malloc(sizeof(t_token));
	tok->content = ft_substr(cmd, i, count);
	ft_get_type(tok);
	tok->path = ft_get_path(env, cmd);
	tok->next = NULL;
	return (tok);
}
