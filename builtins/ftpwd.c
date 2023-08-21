/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:50 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 20:27:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_pwd(void)
{
	char	*pw;

	pw = getcwd(NULL, 0);
	if (!pw)
	{
		ft_putstr_fd(g_v.current_pwd, 1);
		g_v.ex_stu = 1;
	}
	else
	{
		ft_putstr_fd(pw, 1);
		ft_putstr_fd("\n", 1);
		g_v.ex_stu = 0;
	}
	free(pw);
}
