/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_m_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:20:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/28 18:25:19 by mel-kouc         ###   ########.fr       */
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
