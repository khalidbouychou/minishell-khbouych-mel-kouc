/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:50 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/08 16:34:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_pwd(t_parse *tpwd)
{
	char	*pw;

	pw = getcwd(NULL, 0);
	if (!pw)
	{
		ft_putstr_fd(g_stu.current_pwd,tpwd->fd_output);
		ft_putstr_fd("\n",tpwd->fd_output);
		g_stu.ex_stu = 1;
	}
	else
	{
		ft_putstr_fd(pw, tpwd->fd_output);
		ft_putstr_fd("\n", tpwd->fd_output);
		g_stu.ex_stu = 0;
	}
}
