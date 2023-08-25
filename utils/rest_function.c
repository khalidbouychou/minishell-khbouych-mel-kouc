/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:48:02 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/25 13:19:56 by khbouych         ###   ########.fr       */
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

char	*ft_norm_expand(char *cnt, t_exp v)
{
	if (ft_strcmp(cnt, "0") == 0)
	{
		v.r = ft_strdup("0");
		return (v.r);
	}
	return (NULL);
}
