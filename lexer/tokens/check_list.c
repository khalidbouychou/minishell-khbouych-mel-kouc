/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:05:32 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/17 23:17:26 by mel-kouc         ###   ########.fr       */
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
			if (!tmp->operator && !ptr->operator)
			{
				tmp->content = ft_strjoin(tmp->content, ptr->content);
				tmp->next = ptr->next;
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
		if (tmp->content[i] == '"')
			tmp->content = ft_strtrim(tmp->content, "\"");
		tmp = tmp->next;
	}
}
void	between_oper(t_token *tmp)
{
	t_token	*left_op;
	t_token	*right_op;

	while (tmp)
	{
		if (tmp->operator && tmp->type != SPACE)
		{
			left_op = tmp->prev;
			if (left_op)
			{
				while (!ft_strncmp(left_op->content, " ", 2))
				{
					left_op->prev->next = tmp;
					tmp->prev = left_op->prev;
					free(left_op);
					left_op = tmp->prev;
				}
			}
			right_op = tmp->next;
			while (!ft_strncmp(right_op->content, " ", 2))
			{
				tmp->next = right_op->next;
				free(right_op);
				right_op = tmp->next;
			}
		}
		tmp = tmp->next;
	}
}
// void	between_word_var(t_token *tmp)
// {
// 	t_token	*tmp;
// 	t_token	*ptr;

// 	tmp = *lst;
// 	ptr = tmp->next;
// 	if (ptr)
// 	{
// 		while (ptr)
// 		{
// 			if (!ft_strncmp(ptr->content, " ", 1))
// 			{
// 				tmp->next = ptr->next;
// 				free(ptr);
// 				ptr = tmp->next;
// 			}
// 			else
// 				break ;
// 		}
// 	}
// }
void	remove_space(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;

	tmp = *lst;
	ptr = tmp->next;
	if (ptr)
	{
		while (ptr)
		{
			if (!ft_strncmp(ptr->content, " ", 2))
			{
				tmp->next = ptr->next;
				free(ptr);
				ptr = tmp->next;
			}
			else
				break ;
		}
	}
	// between_word_var(tmp);
	between_oper(tmp);
}

void	check_list(t_token **lst)
{
	if (!check_operator(lst) || !check_quotes(lst))
		printf("\nsyntax error near unexpected token \n");
	trim_list(lst);
	lixer_list(lst);
	remove_space(lst);
}
