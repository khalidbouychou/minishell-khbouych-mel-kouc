/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:05:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/22 11:18:46 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

int	check_quotes(t_token **list_tokens)
{
	t_token	*tmp;

	tmp = *list_tokens;
	while (tmp)
	{
		if (check_close_q(tmp) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_operator(t_token **list_tokens)
{
	t_token	*tmp;

	tmp = *list_tokens;
	if (!tmp)
		return (1);
	if (!oper_in_end(*list_tokens))
		return (0);
	if (!check_pipe(*list_tokens))
		return (0);
	if (!successive_oper(*list_tokens))
		return (0);
	return (1);
}

void	lixer_list(t_token **list)
{
	t_token	*tmp;
	t_token	*ptr;
	char	*str;

	tmp = *list;
	str = NULL;
	while (tmp)
	{
		ptr = tmp->next;
		help_lixer_list(str, tmp, ptr);
		tmp = tmp->next;
	}
}

void	trim_list(t_token **list)
{
	t_token	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		ptr = tmp->content;
		if (tmp->content[i] == '\'')
		{
			tmp->content = ft_strtrim(tmp->content, "'");
			free(ptr);
		}
		else if (tmp->content[i] == '"')
		{
			tmp->content = ft_strtrim(tmp->content, "\"");
			free(ptr);
		}
		tmp = tmp->next;
	}
}

int	check_list(t_token **lst, t_env *env)
{
	if (!check_operator(lst) || !check_quotes(lst))
	{
		ft_putstr_fd("-->syntax error near unexpected token \n", 2);
		g_v.ex_stu = 258;
		free_token_list(lst);
		return (0);
	}
	check_herdoc_quotes(*lst);
	trim_list(lst);
	ft_expander(*lst, env);
	lixer_list(lst);
	rm_node_white_space(lst);
	return (1);
}
