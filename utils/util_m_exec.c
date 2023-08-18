/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_m_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:20:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/18 14:56:27 by mel-kouc         ###   ########.fr       */
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
