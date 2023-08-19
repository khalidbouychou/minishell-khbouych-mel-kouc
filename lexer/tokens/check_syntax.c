/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:23 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/19 19:14:49 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

int	check_pipe(t_token	*list_tokens)
{
	t_token	*tmp;

	tmp = list_tokens;
	if (!ft_strcmp((*tmp).content, "|"))
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "|"))
		{
			if (tmp->next == NULL || !ft_strcmp(tmp->next->content, "|"))
				return (0);
			while (!ft_strcmp(tmp->next->content, " ")
				|| !ft_strcmp(tmp->next->content, "	"))
			{
				tmp = tmp->next;
				if (!ft_strcmp(tmp->next->content, "|"))
					return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_close_q(t_token *tmp)
{
	int		flag;
	char	c;
	int		i;

	flag = 0;
	i = 0;
	while (tmp->content[i])
	{
		if (!flag)
		{
			if (tmp->content[i] == '"' || tmp->content[i] == '\'')
			{
				c = tmp->content[i];
				flag = 1;
			}
		}
		else
			if (tmp->content[i] == c)
				flag += 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (-1);
}

int	oper_in_end(t_token	*list_tokens)
{
	t_token	*tmp;

	tmp = list_tokens;
	while (tmp)
	{
		if (tmp->operator == 1 && tmp->type != SPC && tmp->type != _TAB)
		{
			if (tmp->next == NULL)
				return (0);
			else if (!ft_strcmp(tmp->next->content, " ")
				|| !ft_strcmp(tmp->next->content, "	"))
			{
				if (!check_spases(tmp->next))
					return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	util_successive_oper(t_token *tmp)
{
	if (tmp->operator == 1 && tmp->type != SPC && tmp->type != PIPE
		&& tmp->type != _TAB && tmp->next->operator == 1
		&& tmp->next->type != SPC && tmp->next->type != PIPE
		&& tmp->next->type != _TAB)
		return (0);
	else if (tmp->operator == 1 && tmp->type != SPC && tmp->type != PIPE
		&& tmp->type != _TAB)
	{
		while (!ft_strcmp(tmp->next->content, " ")
			|| !ft_strcmp(tmp->next->content, "	"))
		{
			tmp = tmp->next;
			if (tmp->next->operator == 1 && tmp->next->type != SPC
				&& tmp->next->type != _TAB)
				return (0);
		}
	}
	return (1);
}

int	successive_oper(t_token *list_tokens)
{
	t_token	*tmp;
	t_token	*ptr;

	tmp = list_tokens;
	while (tmp)
	{
		ptr = tmp->next;
		if (!util_successive_oper(tmp))
			return (0);
		if ((tmp->type == INPUT || tmp->type == APPND
				|| tmp->type == HERDOC) && (tmp->next->type == PIPE))
			return (0);
		if (ptr && ptr->next)
		{
			if (ptr->next && tmp->type == OUTPUT && ptr->type == PIPE
				&& ptr->next->operator == 1 && ptr->next->type != SPC)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
