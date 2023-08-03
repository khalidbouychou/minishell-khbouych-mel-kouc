/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:53 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/03 19:56:47 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	size_parse_lst(t_parse *lst_p)
{
	t_parse	*tmp;
	int		count;

	count = 0;
	tmp = lst_p;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	complex_cmd(t_parse *lst_p, t_env *env, char **str)
{
	int	size;

	size = size_parse_lst(lst_p);
	if (size == 2)
		one_pipe(lst_p, env, str);
	// else
	// 	multiple_pipe(lst_p, str);
	// (void)env;
}
