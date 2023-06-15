/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/15 22:53:33 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

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
void	lixer_list(t_token **list)
{
	t_token	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (!tmp->operator && tmp->type != SPACE
			&& !tmp->next->operator && tmp->next->type != SPACE)
			
		tmp = tmp->next;
	}
	// tmp->prev->next = tmp ->next
	// free tmp
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
	lixer_list(&lst);
	return (lst);
}
