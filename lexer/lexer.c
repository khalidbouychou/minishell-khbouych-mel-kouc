/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:22:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/21 13:06:02 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	// if (dest == NULL || src == NULL)
	// 	return NULL;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

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

void	ft_set_oper(t_token *tok)
{
	if (tok->type != WORD && tok->type != VAR)
		tok->operator = 1;
	else
		tok->operator = 0;
}

void	test(t_token *ptr)
{
	int		flag;
	t_token	*new;

	flag = 0;
	if (ptr->next && ptr->type == FIL
		&& (ptr->next->type == VAR || ptr->next->type == WORD))
	{
		new = ft_init_token(" ", 0, 1);
		new->next = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}

t_token	*echo_and_n(t_token *ptr, t_token *space)
{
	if (ft_check_n(ptr->content))
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
	else
	{
		while ((ptr && ptr->operator == 0)
			|| (ptr && ptr->operator == 1 && ptr->type == SPACE))
			ptr = ptr->next;
		while ((ptr && ptr->type != PIPE))
		{
			test(ptr);
			ptr = ptr->next;
		}
	}
	return (ptr);
}
// int	error_pipe(char *commande)
// {
// 	int	i;
// 	int	pipe_index;

// 	i = 0;

// 	pipe_index = ft_strchr(commande, '|');
// 	if (commande[0] == '|')
// 		return (0);
// 	if (pipe_index != -1 && !check_spases(commande, pipe_index))
// 		return (0);
// 	i++;
// 	return (1);
// }

// char	*lexer(char *commande)
// {
// 	if (!error_pipe(commande))
// 	{
// 		printf("error");
// 		exit(1);
// 	}
// 	return (commande);
// }
