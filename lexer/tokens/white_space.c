/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:36 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/21 09:19:10 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incld/minishell.h"

void	between_oper(t_token **lst)
{
	t_token	*left_op;
	t_token	*right_op;
	t_token	*tmp;

	left_op = NULL;
	right_op = NULL;
	tmp = *lst;
	while (tmp)
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
		tmp = tmp->next;
	}
}

void	between_word_var(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;

	tmp = *lst;
	tmp = tmp->next;
	while (tmp)
	{
		ptr = tmp->next;
		if (ptr)
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
		tmp = tmp->next;
	}
}

void	after_f_cmd(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;

	tmp = *lst;
	ptr = tmp->next;
	if (ptr)
	{
		while (ptr)
		{
			if (!ft_strncmp(ptr->content, " ", 2)
				|| !ft_strncmp(ptr->content, "	", 2))
			{
				tmp->next = ptr->next;
				if (ptr->next)
				{
					ptr->next->prev = tmp;
					free(ptr);
				}
				ptr = tmp->next;
			}
			else
				break ;
		}
	}
}

void	rm_node_white_space(t_token **lst)
{
	t_token	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	after_f_cmd(lst);
	between_oper(lst);
	between_word_var(lst);
}
