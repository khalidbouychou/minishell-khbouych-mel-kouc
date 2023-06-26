/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/24 11:13:29 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

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
