/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:48:02 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/25 02:51:24 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*return_v_r(t_exp *v, char *cnt)
{
	if (v->r != NULL)
		free(v->r);
	v->r = ft_strdup(cnt);
	return (v->r);
}

char	*ft_trim_spaces_echo(char *tmp)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(tmp))
	{
		if (tmp[i] == 32)
		{
			i++;
			while (tmp && tmp[i] == 32)
			{
				tmp[i] = 31;
				i++;
			}
		}
		i++;
	}
	return (tmp);
}
