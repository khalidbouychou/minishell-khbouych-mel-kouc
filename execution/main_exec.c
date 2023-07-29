/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:44:27 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/29 18:35:19 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	cmd_in_built(t_parse *list_pars, t_env *env)
{
	t_parse	*tmp;
	int		check_fd;

	(void)env;
	tmp = list_pars;
	while (tmp)
	{
		if (tmp->fd_input == -1 || tmp->fd_output == -1)
			check_fd = 0;
		else if (!ft_strcmp(tmp->arg[0], "echo"))
		{
			printf("\n----->test echo\n");
			ft_echo(tmp->arg, 1);
		}
		else if (!ft_strcmp(tmp->arg[0], "env"))
		{
			printf("\n----->test env \n");
		}
		else if (!ft_strcmp(tmp->arg[0], "export"))
		{
			printf("\n----->test export\n");
			// ft_export(tmp->arg, tmp->fd_output);
		}
		else if (!ft_strcmp(tmp->arg[0], "pwd"))
		{
			printf("\n----->test pwd\n");
			
		}
		else if (!ft_strcmp(tmp->arg[0], "exit"))
		{
			printf("\n----->test exit\n");
			
		}
		else if (!ft_strcmp(tmp->arg[0], "unset"))
		{
			printf("\n----->test unset\n");
			
		}
		else if (!ft_strcmp(tmp->arg[0], "cd"))
		{
			printf("\n----->test cd\n");
			
		}
		tmp = tmp->next;
	}
}

void	execute_main(t_parse *list_pars, t_env *env)
{
	char	**str;
	// int i = 0;

	str = NULL;
	str = list_to_char(env, str);
	// while (str[i])
	// {
	// 	printf("double pointer = {%s}\n", str[i]);
	// 	i++;
	// }
	if (!list_pars->next)
	{
		if (compare_cmd(list_pars))
			cmd_in_built(list_pars, env);
		else
		{
			printf("\n CMD NOT IN BUILTINS --->FORk\n");
			simple_not_built(list_pars, env);
			// fork()
		}
	}
	else
	{
		printf("\nCOMPLEX COMMAND ---> FORK\n");
		// complex_cmd(list_pars, env);
		// fork()
	}
}
