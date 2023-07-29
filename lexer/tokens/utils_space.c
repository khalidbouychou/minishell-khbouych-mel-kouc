/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:25:19 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/29 16:56:51 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

void	util_between_word_var(t_token *ptr, t_token	*tmp)
{
	while (ptr)
	{
		if ((ptr->next && ptr->type == SPACE && ptr->next->type == SPACE))
		{
			tmp->next = ptr->next;
			ptr->next->prev = tmp;
			free(ptr);
		}
		else
			break ;
		ptr = tmp->next;
	}
	if (!ptr->next)
	{
		if (ptr->type == SPACE)
		{
			ptr->prev->next = NULL;
			free(ptr);
		}
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
			while (space && space->type == SPACE)
			{
				cmd->next = space->next;
				if (space->next)
					space->next->prev = cmd;
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
	if (!ft_strncmp(tmp->content, "echo", 5))
	{
		ptr = echo_and_n(ptr, space);
		*flag = 1;
	}
	else
	{
		while (ptr && ptr->operator == 0 && ptr->type != SPACE && *flag == 0)
		{
			space = ptr->next;
			if (space && space->type == SPACE)
			{
				ptr->next = space->next;
				space->next->prev = ptr;
				free (space);
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
