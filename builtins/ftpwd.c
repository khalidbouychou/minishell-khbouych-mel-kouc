/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:50 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/24 18:29:52 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_pwd(int fd)
{
	char	*pw;

	pw = getcwd(NULL, 0);
	if (!pw)
	{
		ft_putstr_fd(g_v.current_pwd, fd);
		ft_putstr_fd("\n", fd);
		g_v.ex_stu = 1;
	}
	else
	{
		ft_putstr_fd(pw, fd);
		ft_putstr_fd("\n", fd);
		g_v.ex_stu = 0;
	}
	free(pw);
}
