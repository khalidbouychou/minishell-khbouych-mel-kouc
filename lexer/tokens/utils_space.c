/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:25:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/21 20:36:24 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

int	check_spases(t_token *tmp)
{
	while (!ft_strncmp(tmp->content, " ", 2)
		|| !ft_strncmp(tmp->content, "	", 2))
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (0);
	}
	return (1);
}

void	util_between_word_var(t_token *ptr, t_token	*tmp)
{
	while (ptr)
	{
		if ((ptr->next && ptr->type == SPACE && ptr->next->type == SPACE)
			|| (ptr->next && ptr->type == SPACE && ptr->next->type == TAB)
			|| (ptr->next && ptr->type == TAB && ptr->next->type == SPACE)
			|| (ptr->next && ptr->type == TAB && ptr->next->type == TAB))
		{
			tmp->next = ptr->next;
			ptr->next->prev = tmp;
			free(ptr);
		}
		else
			break ;
		ptr = tmp->next;
	}
}

void	util_between_oper(t_token *tmp, t_token	*right_op, t_token	*left_op)
{
	if (tmp->operator && tmp->type != SPACE && tmp->type != TAB)
	{
		left_op = tmp->prev;
		if (left_op)
		{
			while (!ft_strncmp(left_op->content, " ", 2)
				|| !ft_strncmp(left_op->content, "	", 2))
			{
				left_op->prev->next = tmp;
				tmp->prev = left_op->prev;
				free(left_op);
				left_op = tmp->prev;
			}
		}
		right_op = tmp->next;
		while (!ft_strncmp(right_op->content, " ", 2)
			|| !ft_strncmp(right_op->content, "	", 2))
		{
			tmp->next = right_op->next;
			right_op->next->prev = tmp;
			free(right_op);
			right_op = tmp->next;
		}
	}
}

void	space_after_cmd(t_token **lst)
{
	t_token	*tmp;
	t_token	*cmd;
	t_token	*space;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->operator && tmp->type != SPACE
			&& tmp->next->operator != 1)
		{
			cmd = tmp->next;
			space = cmd->next;
			if (space)
			{
				cmd->next = space->next;
				space->next->prev = cmd;
				free(space);
			}
		}
		tmp = tmp->next;
	}
}
