/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:48:02 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/25 16:31:24 by mel-kouc         ###   ########.fr       */
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

char	*ft_return_ret(char **cmd, char *ret, char *p)
{
	ret = ft_check_if_cmd_valid(ft_split(p, ':'), cmd[0]);
	free_char_double(cmd);
	return (ret);
}

char	*ft_process_command(char **cmd)
{
	char	*get_cmd;

	get_cmd = NULL;
	get_cmd = ft_strdup(cmd[0]);
	free_char_double(cmd);
	return (get_cmd);
}
