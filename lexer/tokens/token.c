/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/16 15:19:03 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

char	*ft_check_if_cmd_valid(char **path, t_token *tok)
{
	int		i;
	char	*p;

	p = NULL;
	i = 0;
	while (path[i])
	{
		p = ft_strjoin(path[i], "/");
		p = ft_strjoin(p, tok->content);
		if (access(p, X_OK | F_OK) == 0)
			return (p);
		i++;
	}
	return (NULL);
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

int	ft_count_alloc(char *cmd, int i, t_token **list, t_env *env)
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
	else if (cmd[i] == '|' || cmd[i] == ' ' || cmd[i] == '>' || cmd[i] == '<')
	{
		count = 1;
		i = i + count;
	}
	else if ((cmd[i] == '\"' || cmd[i] == '\''))
		count = ft_qoutes(cmd, &i, init);
	else
		count = ft_word(cmd, &i, init);
	ft_add_to_list_tokens(list, ft_init_token(cmd, init, count, env));
	return (i);
}

char	*ft_strsearch(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}
char	*ft_strtrim(char *s1, char *set)
{
	int		lens2;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_strsearch(set, s1[i]))
		i++;
	lens2 = ft_strlen(s1);
	while (lens2 && ft_strsearch(set, s1[lens2]))
		lens2--;
	return (ft_substr(s1, i, lens2 + 1 - i));
}
void	lixer_list(t_token **list)
{
	t_token	*tmp;
	t_token	*ptr;

	tmp = *list;
	while (tmp)
	{
		ptr = tmp->next;
		while (ptr)
		{
			if (!tmp->operator && !ptr->operator)
			{
				tmp->content = ft_strjoin(tmp->content, ptr->content);
				tmp->next = ptr->next;
				free(ptr);
			}
			else
				break ;
			ptr = tmp->next;
		}
		tmp = tmp->next;
	}
}
void	trim_list(t_token **list)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content[i] == '\'')
			tmp->content = ft_strtrim(tmp->content, "'");
		if (tmp->content[i] == '"')
			tmp->content = ft_strtrim(tmp->content, "\"");
		tmp = tmp->next;
	}
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
			i = ft_count_alloc(cmd, i, &lst, env);
		else if (cmd[i] == ' ')
			i = ft_count_alloc(cmd, i, &lst, env);
		else if (cmd[i] == '>')
			i = ft_count_alloc(cmd, i, &lst, env);
		else if (cmd[i] == '<')
			i = ft_count_alloc(cmd, i, &lst, env);
		else
			i = ft_count_alloc(cmd, i, &lst, env);
	}
	if (!check_operator(&lst) || !check_quotes(&lst))
		printf("\nsyntax error near unexpected token \n");
	trim_list(&lst);
	lixer_list(&lst);
	return (lst);
}
