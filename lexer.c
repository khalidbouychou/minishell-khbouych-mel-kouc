/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:04:13 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/27 19:07:04 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

int	check_spases(char *commande, int index)
{
	int	j;

	j = index + 1;
	while (commande[j])
	{
		if (commande[j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int	error_pipe(char *commande)
{
	int	i;
	int	pipe_index;

	i = 0;

	pipe_index = ft_strchr(commande, '|');
	if (commande[0] == '|')
		return (0);
	if (pipe_index != -1 && !check_spases(commande, pipe_index))
		return (0);
	i++;
	return (1);
}

char	*lexer(char *commande)
{
	if (!error_pipe(commande))
	{
		printf("error");
		exit(1);
	}
	return (commande);
}
