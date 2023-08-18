/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:25:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/17 12:00:02 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

void	util_between_word_var(t_token *ptr, t_token	*tmp)
{
	while (ptr)
	{
		if ((ptr->next && ptr->type == SPC && ptr->next->type == SPC))
		{
			tmp->next = ptr->next;
			ptr->next->prev = tmp;
			free(ptr->content);
			free(ptr);
		}
		else
			break ;
		ptr = tmp->next;
	}
	if (!ptr->next)
	{
		if (ptr->type == SPC)
		{
			ptr->prev->next = NULL;
			free(ptr->content);
			free(ptr);
		}
	}
}

void	util_between_oper(t_token *tmp, t_token	*right_op, t_token	*left_op)
{
	if (tmp->operator && tmp->type != SPC && tmp->type != _TAB)
	{
		left_op = tmp->prev;
		if (left_op)
		{
			while (!ft_strcmp(left_op->content, " ")
				|| !ft_strcmp(left_op->content, "	"))
			{
				left_op->prev->next = tmp;
				tmp->prev = left_op->prev;
				free(left_op->content);
				free(left_op);
				left_op = tmp->prev;
			}
		}
		operator_right(tmp, right_op);
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
		if (tmp->operator && tmp->type != SPC
			&& tmp->next->operator != 1)
		{
			cmd = tmp->next;
			space = cmd->next;
			while (space && space->type == SPC)
			{
				cmd->next = space->next;
				if (space->next)
					space->next->prev = cmd;
				free(space->content);
				free(space);
				space = cmd->next;
			}
		}
		tmp = tmp->next;
	}
}

t_token	*check_echo(t_token *tmp, t_token *ptr, t_token *space, int *flag)
{
	ft_tolower(tmp->content);
	if (!ft_strcmp(tmp->content, "echo"))
	{
		ptr = echo_and_n(ptr, space);
		*flag = 1;
	}
	else
	{
		while (ptr && ptr->operator == 0 && ptr->type != SPC && *flag == 0)
		{
			space = ptr->next;
			if (space && space->type == SPC)
			{
				ptr->next = space->next;
				space->next->prev = ptr;
				free(space->content);
				free(space);
			}
			ptr = ptr->next;
		}
	}
	return (ptr);
}

void	check_cmd(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;
	t_token	*space;
	int		flag;

	flag = 0;
	space = NULL;
	tmp = *lst;
	while (tmp)
	{
		ptr = tmp->next;
		if (ptr)
			ptr = check_echo(tmp, ptr, space, &flag);
		if (!ptr)
			break ;
		tmp = ptr->next;
	}
}
