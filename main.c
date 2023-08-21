/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 00:05:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incld/minishell.h"

void	help_main(char *cmd, t_env **env)
{
	t_token		*list_tokens;
	t_parse		*list_parser;

	list_tokens = NULL;
	list_parser = NULL;
	list_tokens = divide(cmd, *env);
	g_v.sig = 0;
	if (list_tokens)
	{
		list_parser = parser(list_tokens, *env);
		
		execute_main(list_parser, env);
	}
	free_token_list(&list_tokens);
	// free_parser_list(&list_parser);
	g_v.sig = 1;
}

void	ft_init_variables(void)
{
	g_v.ex_stu = 0;
	g_v._flag = 0;
	g_v.sig = 0;
}


int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;

	(void)argc;
	(void)argv;
	cmd = NULL;
	env = env_list(envp);
	ft_init_variables();
	ft_signals();
	g_v.sig = 1;
	while (1997)
	{
		cmd = readline("minishell ~> ");
		// if (ft_strcmp(cmd, "./minishell") == 0)
		// 	g_v._flag = 1;
		add_history(cmd);
		if (cmd)
			help_main(cmd, &env);
		else
		{
			write(1, "exit\n", 6);
			break ;
		}
		free (cmd);
	}
}
