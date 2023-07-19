/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst_parce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/19 21:56:21 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

t_parse	*ft_last_parser(t_parse *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	alloc_arg(t_token *tmp)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		if (tmp->type == WORD || tmp->type == VAR || tmp->type == SPACE)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

void	add_to_list_parser(t_parse **lst_tok, t_parse *newtok)
{
	t_parse	*last;

	if (*lst_tok == NULL)
		*lst_tok = newtok;
	else
	{
		printf("\n the error is after this line \n");
		last = ft_last_parser(*lst_tok);
		printf("\n the error is befor this line \n");
		last->next = newtok;
	}
}

void	init_parce(t_parse *list)
{
	list->fd_input = -4;
	list->fd_output = -5;
	list->fd_heredoc = -6;
	list->name = NULL;
	list->arg = NULL;
}

// void	ft_strcopy(char *s1, char *s2, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (i < j)
// 	{
// 		s1[i] = s2[i];
// 		i++;
// 	}
// 	s1[i] = '\0';
// }

// t_token	*return_operator(t_token *node)
// {
// 	while (node->content)
// 	{
// 		if (node->operator && node->type != SPACE)
// 			return (node);
// 		node = node->next;
// 		if (node == NULL)
// 			return (NULL);
// 	}
// 	return (NULL);
// }

// int	ft_count_word(t_token *list_tokens)
// {
// 	int		word;
// 	int		flag;
// 	t_token	*tmp;

// 	word = 0;
// 	flag = 0;
// 	tmp = list_tokens;
// 	while (tmp)
// 	{
// 		while (tmp->type == SPACE)
// 		{
// 			tmp = tmp->next;
// 		}
// 		if (!tmp->operator)
// 			word++;
// 		tmp = return_operator(tmp);
// 		if (!tmp)
// 			return (word);
// 		else
// 			word++;
// 		tmp = tmp->next;
// 	}

// 	return (word);
// }

// void	split_operator(t_token *list_tokens)
// {
// 	t_parse	*operator;
// 	t_parse	*tmp;
// 	int		i;
// 	int		word;
// 	int		flag;

// 	// tmp-> = NULL;
// 	// operator = NULL;
// 	flag = 0;
// 	// *(tmp->split) = NULL;
// 	i = 0;
// 	// *(tmp->split) = ft_strdup("\0");
// 	tmp->ptr = list_tokens;
// 	word = ft_count_word(list_tokens);
//     printf("\nword = %d\n", word);
// 	tmp->arg = malloc(sizeof(char *) *(word + 1));
// 	operator->ptr = return_operator(tmp->ptr);
// 	while (tmp)
// 	{
// 		if (!flag)
// 		{
// 			operator->ptr = return_operator(tmp->ptr);
// 			flag = 1;
// 		}
// 		if (operator->ptr)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     )
// 		{
// 			if (ft_strncmp(tmp->ptr->content, operator->ptr->content, ft_strlen(tmp->ptr->content)))
// 			{
// 				printf("\nhello\n");
// 				if (*(tmp->arg) == NULL)
// 					*(tmp->arg) = ft_strdup(tmp->ptr->content);
// 				else
// 					tmp->arg[i] = ft_strjoin(tmp->arg[i], tmp->content);
// 				i++;
// 			}
// 			else
// 				flag = 0;
// 		}
// 		// else
// 		// {
// 		// 	if (*(tmp->arg) == NULL)
// 		// 		*(tmp->arg) = ft_strdup(tmp->content);
// 		// 	else
// 		// 		tmp->arg[i] = ft_strjoin(tmp->arg[i], tmp->content);
// 		// 	i++;
// 		// }
// 		tmp = tmp->next;
// 	}
// 	tmp->arg[i] = NULL;
// }
