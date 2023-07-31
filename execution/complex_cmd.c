/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:53 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/30 18:38:12 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	complex_cmd(t_parse *lst_p, t_env *env, char **str)
{
	int	pid;
	// int	fd[2];

	// pipe(fd);
	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		
	}
	printf("\nCOMPLEX COMMAND ---> FORK\n");
	(void)lst_p;
	(void)env;
	(void)str;
}
