/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:50 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/29 16:40:09 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_pwd(void)
{
	char	*pw;

	pw = getcwd(NULL, 0);
	if (!pw)
	{
		ft_putstr_fd("minishell: pwd: ", 1);
		g_stu.ex_stu = 1;
	}
	ft_putstr_fd(pw, 1);
	ft_putstr_fd("\n", 1);
	g_stu.ex_stu = 0;
}
