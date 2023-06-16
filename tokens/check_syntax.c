/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:23 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/16 11:26:41 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	check_spases(t_token *tmp)
{
	while (!ft_strncmp(tmp->content, " ", 1))
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (0);
	}
	return (1);
}

int	check_pipe(t_token	*list_tokens)
{
	t_token	*tmp;

	tmp = list_tokens;
	if (!ft_strncmp((*tmp).content, "|", 1))
		return (0);
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, "|", 1))
		{
			if (tmp->next == NULL || !ft_strncmp(tmp->next->content, "|", 1))
				return (0);
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

int	check_operator(t_token	**list_tokens)
{
	t_token	*tmp;

	tmp = *list_tokens;
	if (!tmp)
		return (1);
	if (!check_pipe(*list_tokens))
		return (0);
	while (tmp)
	{
		if (tmp->operator == 1 && tmp->type != SPACE)
		{
			if (tmp->next == NULL)
				return (0);
			else if (!ft_strncmp(tmp->next->content, " ", 1))
			{
				if (!check_spases(tmp->next))
					return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
