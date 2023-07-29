/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/28 20:44:46 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"
#include <sys/types.h>

void	ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

void	print(t_token *lst)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	i = 0;
	printf("\n--------------TOKEN_LIST----------------\n");
	while (tmp && tmp->content)
	{
		printf("√ cmd\t--> (%s)\n", tmp->content);
		printf("√ type\t--> (%d)\n", tmp->type);
		printf("√ is_op\t--> (%d)\n", tmp->operator);
		printf("√ flag\t--> (%d)\n", tmp->flag);
		// printf("√ path\t--> (%s)\n", tmp->path);
		printf("\n------------------------------------\n");
 		tmp = tmp->next;
		i++;
	}
}
void	parser_print(t_parse *lst)
{
	t_parse	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = lst;
	printf("\n ----------------PARSER_LIST---------------\n");
	while (tmp)
	{
		j = 0;
		while (tmp->arg[j])
		{
			printf("√ cmd\t--> (%s)\n", tmp->arg[j]);
			j++;
		}
		printf("√ \n***** fd int = %d *****\n", tmp->fd_input);
		printf("√ \n***** fd out = %d *****\n", tmp->fd_output);
		// printf("√ path\t--> (%s)\n", tmp->path);
		printf("\n------------------------------------\n");
 		tmp = tmp->next;
	}
}

// void	l()
// {
// 	system("leaks ./minishell");
// }

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;
	t_token	*list_tokens;
	t_parse	*list_parser;

	// atexit(l);
	(void)argc;
	(void)argv;
	cmd = NULL;
	list_tokens = NULL;
	list_parser = NULL;
	env = env_list(envp);
	// signal(SIGINT,_handler);
	// signal(SIGQUIT,_handler);
	// ft_export(argv,env);
	// ft_echo(argv,1);
	while (1)
	{
		cmd = readline("minishell ~> ");
		if (cmd)
		{
			add_history(cmd);
			list_tokens = divide(cmd, env);
			// print(list_tokens);
			list_parser = parser(list_tokens, env);
			execute_main(list_parser, env);
			// parser_print(list_parser);
		}
		else
		{
			ft_putendl_fd("\nexit", 1);
			break ;
		}
		free (cmd);
	}
}
