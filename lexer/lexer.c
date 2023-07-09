/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:22:35 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/09 16:25:59 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../incld/minishell.h"

char	*ft_strncpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
