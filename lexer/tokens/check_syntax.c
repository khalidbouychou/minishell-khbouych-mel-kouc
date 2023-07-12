/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:23 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/12 12:16:05 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

int	check_pipe(t_token	*list_tokens)
{
	t_token	*tmp;

	tmp = list_tokens;
	if (!ft_strncmp((*tmp).content, "|", 2))
		return (0);
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, "|", 2))
		{
			if (tmp->next == NULL || !ft_strncmp(tmp->next->content, "|", 1))
				return (0);
			while (!ft_strncmp(tmp->next->content, " ", 2)
				|| !ft_strncmp(tmp->next->content, "	", 2))
			{
				tmp = tmp->next;
				if (!ft_strncmp(tmp->next->content, "|", 2))
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
		if (tmp->operator == 1 && tmp->type != SPACE && tmp->type != TAB)
		{
			if (tmp->next == NULL)
				return (0);
			else if (!ft_strncmp(tmp->next->content, " ", 2)
				|| !ft_strncmp(tmp->next->content, "	", 2))
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
	t_token	*ptr;
	// int		flag;

	// if (tmp->next && tmp->type == OUTPUT && tmp->next->type == PIPE)
	// 	flag = 1;
	 if (tmp->operator == 1 && tmp->type != SPACE && tmp->type != PIPE
		&& tmp->type != TAB && tmp->next->operator == 1
		&& tmp->next->type != SPACE && tmp->next->type != PIPE
		&& tmp->next->type != TAB)
		return (0);
	else if (tmp->operator == 1 && tmp->type != SPACE && tmp->type != PIPE
		&& tmp->type != TAB)
	{
		while (!ft_strncmp(tmp->next->content, " ", 2)
			|| !ft_strncmp(tmp->next->content, "	", 2))
		{
			tmp = tmp->next;
			if (tmp->next->operator == 1 && tmp->next->type != SPACE
				&& tmp->next->type != TAB)
				return (0);
		}
	}
	return (1);
}
// int	oper_error(t_token *tmp)
// {
// 	t_token	*ptr;

// 	ptr = tmp->next;
// 	if ((tmp->type == INPUT || tmp->type == APPND
// 			|| tmp->type == HERDOC) && (tmp->next->type == PIPE))
// 		return (0);
// 	if (ptr && ptr->next)
// 	{
// 		if (ptr->next && tmp->type == OUTPUT && ptr->type == PIPE
// 			&& ptr->next->operator == 1 && ptr->next->type != SPACE)
// 			return (0);
// 	}
// 	return (1);
// }

// int	search_outp_pipe(t_token *tmp)
// {
// 	t_token	*ptr;

// 	ptr = tmp->next;
// 	while (ptr && tmp->type == OUTPUT
// 		&& (ptr->type == SPACE || ptr->type == TAB))
// 		ptr = ptr->next;
// 	if (ptr && ptr->type == PIPE)
// 		return (0);
// 	return (1);
// }

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
		ptr = tmp->next;
		if ((tmp->type == INPUT || tmp->type == APPND
				|| tmp->type == HERDOC) && (tmp->next->type == PIPE))
			return (0);
		if (ptr && ptr->next)
		{
			if (ptr->next && tmp->type == OUTPUT && ptr->type == PIPE
				&& ptr->next->operator == 1 && ptr->next->type != SPACE)
				return (0);
		}
		// if (!search_outp_pipe(tmp))
		// 	return (0);
		tmp = tmp->next;
	}
	return (1);
}
