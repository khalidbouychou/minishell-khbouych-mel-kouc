/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:44:27 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/26 00:26:57 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	check_cmd_bult(t_parse *list_pars)
{
	t_parse	*tmp;

	tmp = list_pars;
	while (tmp)
	{
		printf("\nhello");
		if (!ft_strncmp(tmp->arg[0], "echo", 5))
		{
			printf("\n----->test echo\n");
			// ft_echo(tmp->arg, 1);
		}
		else if (!ft_strncmp(tmp->arg[0], "env", 4))
		{
			printf("\n----->test env \n");
		}
		else if (!ft_strncmp(tmp->arg[0], "export", 7))
		{
			printf("\n----->test export\n");
			// ft_export(tmp->arg, tmp->fd_output);
		}
		else if (!ft_strncmp(tmp->arg[0], "pwd", 4))
		{
			printf("\n----->test pwd\n");
			
		}
		else if (!ft_strncmp(tmp->arg[0], "exit", 5))
		{
			printf("\n----->test exit\n");
			
		}
		else if (!ft_strncmp(tmp->arg[0], "unset", 6))
		{
			printf("\n----->test unset\n");
			
		}
		else if (!ft_strncmp(tmp->arg[0], "cd", 3))
		{
			printf("\n----->test cd\n");
			
		}
		printf("\n*******  \\\\\\\\\\ ********\n");
		tmp = tmp->next;
	}
}


void    execute_main(t_parse *list_pars)
{
	check_cmd_bult(list_pars);
}
