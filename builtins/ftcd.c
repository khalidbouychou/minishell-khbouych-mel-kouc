/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/31 18:35:35 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_cd(char **cmd, t_env *e)
{
	int		flag;

	flag = 0;
	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
	{
		chdir(ft_get_env(e, "HOME"));
		g_stu.ex_stu = 0;
		return ;
	}
	else if (flag || chdir(cmd[1]) == -1)
	{
		flag = 0;
		g_stu.ex_stu = 1;
		printf("--> cd : |%s| No such file or directory \n", cmd[1]);
	}
	else
	{
		flag = 1;
		g_stu.ex_stu = 0;
	}
}
