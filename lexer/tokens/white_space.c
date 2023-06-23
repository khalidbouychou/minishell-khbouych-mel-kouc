/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:02:36 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/23 17:15:14 by mel-kouc         ###   ########.fr       */
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
		util_between_oper(tmp, right_op, left_op);
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
			util_between_word_var(ptr, tmp);
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

void	switch_sp_free(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;


	tmp = *lst;
	while (tmp)
	{
		if (tmp->type == TAB)
		{
			tmp->content = ft_strdup(" ");
			tmp->type = SPACE;
		}
		ptr = tmp;
		tmp = tmp->next;
	}
	if (ptr->type == SPACE)
	{
		ptr->prev->next = tmp;
		free(ptr);
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
	switch_sp_free(lst);
	space_after_cmd(lst);
}
