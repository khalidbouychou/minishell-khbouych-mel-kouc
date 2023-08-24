/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_m_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:20:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/24 13:26:01 by khbouych         ###   ########.fr       */
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

char	*findpathvalue(t_env *head)
{
	t_env	*tmp;
	char	*p;

	p = NULL;
	tmp = head;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, "PATH"))
		{
			p = tmp->value;
			break ;
		}
		tmp = tmp->next;
	}
	return (p);
}
