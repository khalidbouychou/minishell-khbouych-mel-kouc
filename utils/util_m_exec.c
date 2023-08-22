/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_m_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:20:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/22 17:57:18 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	compare_cmd(t_parse *tmp)
{
	if (!ft_strcmp(tmp->arg[0], "echo") || !ft_strcmp(tmp->arg[0], "env")
		|| !ft_strcmp(tmp->arg[0], "export") || !ft_strcmp(tmp->arg[0], "pwd")
		|| !ft_strcmp(tmp->arg[0], "exit") || !ft_strcmp(tmp->arg[0], "unset")
		|| !ft_strcmp(tmp->arg[0], "cd"))
		return (1);
	return (0);
}

int	compare_path(char *tmp)
{
	if (!ft_strcmp(tmp, "echo") || !ft_strcmp(tmp, "env")
		|| !ft_strcmp(tmp, "export") || !ft_strcmp(tmp, "pwd")
		|| !ft_strcmp(tmp, "exit") || !ft_strcmp(tmp, "unset")
		|| !ft_strcmp(tmp, "cd"))
		return (1);
	return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 && *str1 == *str2 && n)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (1);
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
