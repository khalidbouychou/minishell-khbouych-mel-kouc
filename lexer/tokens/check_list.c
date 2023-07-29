/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:05:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/29 18:22:43 by khbouych         ###   ########.fr       */
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

	tmp = *list;
	while (tmp)
	{
		ptr = tmp->next;
		while (ptr)
		{
			if ((!tmp->operator && !ptr->operator))
			{
				tmp->content = ft_strjoin(tmp->content, ptr->content);
				tmp->next = ptr->next;
				ptr->next->prev = tmp;
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
		else if (tmp->content[i] == '"')
			tmp->content = ft_strtrim(tmp->content, "\"");
		tmp = tmp->next;
	}
}

void	check_list(t_token **lst, t_env *env)
{
	if (!check_operator(lst) || !check_quotes(lst))
	{
		printf("syntax error near unexpected token \n");
		free_token_list(lst);
		return ;
		// free_env_list(env);
	}
	check_herdoc_quotes(*lst);
	trim_list(lst);
	// ft_expander(*lst, env);
	(void)env;
	lixer_list(lst);
	rm_node_white_space(lst);
}
