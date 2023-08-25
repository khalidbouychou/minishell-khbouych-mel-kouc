/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/25 16:30:59 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

char	*ft_check_if_cmd_valid(char **path, char *str)
{
	int		i;
	char	*p;
	char	*tmp;

	p = NULL;
	i = 0;
	while (path && path[i])
	{
		p = ft_strjoin(path[i], "/");
		tmp = p;
		p = ft_strjoin(p, str);
		free(tmp);
		if (access(p, X_OK | F_OK) == 0)
		{
			free_char_double(path);
			return (p);
		}
		free(p);
		i++;
	}
	free_char_double(path);
	return (NULL);
}

char	*ft_get_path(t_env *env, char *str)
{
	char	*p;
	t_env	*tmp;
	char	**cmd;
	char	*ret;

	p = NULL;
	cmd = NULL;
	tmp = env;
	ret = NULL;
	if (ft_strchr(str, 32) != -1)
		cmd = ft_split(str, 32);
	if (cmd)
		if (ft_strchr(cmd[0], '/') == -1)
			return (ft_return_ret(cmd, ret, findpathvalue(env)));
	if (cmd)
	{
		if (ft_strchr(cmd[0], '/') == -1)
			return (ft_return_ret(cmd, ret, findpathvalue(env)));
		else
			return (ft_process_command(cmd));
	}
	if (ft_strchr(str, '/') == -1)
		return (ft_check_if_cmd_valid(ft_split(findpathvalue(env), ':'), str));
	else
		return (ft_strdup(str));
}

void	ft_add_to_list_tokens(t_token **lst_tok, t_token *newtok)
{
	t_token	*last;

	if (*lst_tok == NULL)
		*lst_tok = newtok;
	else
	{
		last = ft_listlast(*lst_tok);
		last->next = newtok;
		newtok->prev = last;
	}
}

int	ft_count_alloc(char *cmd, int i, t_token **list)
{
	int	count;
	int	init;

	count = 0;
	init = i;
	if ((cmd[i] == '>' && cmd[i + 1] == '>') || (cmd[i] == '<'
			&& cmd[i + 1] == '<'))
	{
		count = 2;
		i = i + count;
	}
	else if (cmd[i] == '|' || cmd[i] == ' ' || cmd[i] == '>' || cmd[i] == '<'
		|| cmd[i] == '	')
	{
		count = 1;
		i = i + count;
	}
	else if ((cmd[i] == '\"' || cmd[i] == '\''))
		count = ft_qoutes(cmd, &i, init);
	else
		count = ft_word(cmd, &i, init);
	ft_add_to_list_tokens(list, ft_init_token(cmd, init, count));
	return (i);
}

t_token	*divide(char *cmd, t_env *env)
{
	t_token	*lst;
	int		i;

	lst = NULL;
	i = 0;
	while (cmd[i] && cmd[i] == 32)
		i++;
	while (cmd[i])
	{
		if (cmd[i] == '|')
			i = ft_count_alloc(cmd, i, &lst);
		else if (cmd[i] == ' ')
			i = ft_count_alloc(cmd, i, &lst);
		else if (cmd[i] == '>')
			i = ft_count_alloc(cmd, i, &lst);
		else if (cmd[i] == '<')
			i = ft_count_alloc(cmd, i, &lst);
		else if (cmd[i] == '	')
			i = ft_count_alloc(cmd, i, &lst);
		else
			i = ft_count_alloc(cmd, i, &lst);
	}
	if (!check_list(&lst, env))
		return (NULL);
	return (lst);
}
