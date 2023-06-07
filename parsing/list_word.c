/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/07 23:23:24 by mel-kouc         ###   ########.fr       */
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

int	ft_count_word(t_token *list_tokens)
{
	int		word;
	int		flag;

	word = 0;
	flag = 0;
	while (tmp)
	{
		if (tmp->operator && tmp->type != SPACE)
			word++;
		tmp = tmp->next;
	}
	//word++; its fals in this exp ; > file.txt
	return (word);
}

void	split_operator(t_token *list_tokens)
{
	t_token	*tmp;
	int		i;
	int		word;

	tmp = NULL;
	*(tmp->split) = NULL;
	i = 0;
	// *(tmp->split) = ft_strdup("\0");
	tmp = list_tokens;
	word = ft_count_word(list_tokens);
	tmp->split = malloc(sizeof(char *) *(word + 1))
	while (tmp)
	{
		if (!tmp->operator && tmp->type != SPACE)
		{
			if (*(tmp->split) == NULL)
				*(tmp->split) = ft_strdup(tmp->content);
			else
				tmp->split[i] = ft_strjoin(tmp->split[i], tmp->content);
		}
		else
			i++;
		tmp = tmp->next;
	}
	tmp->split[i] = NULL;
}

// char	**ft_split(char *cmd)
// {
// 	int 	i;
// 	char	**split;
// 	int		word;
// 	int		j;
// 	int		k;
// 	t_token	*str;


// 	i = 0;
// 	k = 0;
// 	word = 0;
// 	while (str->content[i])
// 	{
// 		while (str->content[i] && (str->content[i] != '')
// 			str->content[i] != '|' && str->content[i] != ' '
// 			&& str->content[i] != '>' && str->content[i] != '<')
// 			i++;
// 		if (str[i])
// 			word++;
// 		while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
// 			i++;
// 	}
// 	split = (char **)malloc(sizeof(char *) * word + 1);
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'))
// 			i++;
// 		j = i;
// 		while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
// 			i++;
// 		if (j < i)
// 		{
// 			split[k] = (char *)malloc(sizeof(char) * (i - j + 1));
// 			ft_strcopy(split[k], &str[j], i - j );
// 			k++;
// 		}
// 	}
// 	split[k] = NULL;
// 	return(split);
// }