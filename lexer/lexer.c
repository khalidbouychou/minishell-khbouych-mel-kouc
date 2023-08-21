/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:22:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 20:27:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	help_lixer_list(char *str, t_token *tmp, t_token *ptr)
{
	while (ptr)
	{
		if ((!tmp->operator && !ptr->operator))
		{
			str = tmp->content;
			tmp->content = ft_strjoin(tmp->content, ptr->content);
			tmp->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = tmp;
			free(ptr->content);
			free(ptr);
			free(str);
		}
		else
			break ;
		ptr = tmp->next;
	}
}

int	check_spases(t_token *tmp)
{
	while (!ft_strcmp(tmp->content, " ")
		|| !ft_strcmp(tmp->content, "	"))
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (0);
	}
	return (1);
}

void	ft_set_oper(t_token *tok)
{
	if (tok->type != WORD && tok->type != VAR)
		tok->operator = 1;
	else
		tok->operator = 0;
}

void	add_node_space(t_token *ptr)
{
	t_token	*new;
	t_token	*next_ptr;

	next_ptr = NULL;
	if (ptr->next)
	{
		next_ptr = ptr->next;
		if (next_ptr->next && next_ptr->type == FIL
			&& ft_strcmp(ptr->prev->content, "echo")
			&& (next_ptr->next->type == VAR || next_ptr->next->type == WORD))
		{
			new = ft_init_token(" ", 0, 1);
			new->next = next_ptr->next;
			next_ptr->next = new;
			new->prev = next_ptr;
		}
	}
}

t_token	*echo_and_n(t_token *ptr, t_token *space)
{
	if (ft_check_n(ptr->content))
	{
		while (ptr && ft_check_n(ptr->content))
		{
			space = ptr->next;
			if (space && space->type == SPC)
			{
				ptr->next = space->next;
				space->next->prev = ptr;
				free(space->content);
				free (space);
			}
			ptr = ptr->next;
		}
	}
	while ((ptr && ptr->operator == 0)
		|| (ptr && ptr->operator == 1 && ptr->type == SPC))
		ptr = ptr->next;
	while ((ptr && ptr->type != PIPE))
	{
		add_node_space(ptr);
		ptr = ptr->next;
	}
	return (ptr);
}
