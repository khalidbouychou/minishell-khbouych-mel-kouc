/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:48:02 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/25 15:09:16 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*return_v_r(char *cnt, t_exp *v)
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

void	help_ft_test(char	*tmp, char *cnt, size_t *i, char *str)
{
	size_t	j;

	if ((*i) + 1 < ft_strlen(cnt) && cnt[*i] == '$' && cnt[(*i) + 1] == '?')
	{
		j = 0;
		while (str[j])
		{
			tmp[(*i) + 1] = str[j];
			j++;
			(*i)++;
		}
		if (j == 1)
		{
			tmp[(*i) + 1] = 31;
			(*i)++;
		}
	}
	else
	{
		tmp[(*i) + 1] = cnt[*i];
		(*i)++;
	}
}
