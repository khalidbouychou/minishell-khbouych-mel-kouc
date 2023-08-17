/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/17 11:34:36 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"
// #include <sys/types.h>

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
		printf("√ path\t--> (%s)\n", tmp->path);
		printf("\n------------------------------------\n");
 		tmp = tmp->next;
	}
}

// void	l()
// {
// 	system("leaks minishell");
// }

void    help_main(char *cmd, t_env **env)
{
	t_token		*list_tokens;
	t_parse		*list_parser;

	list_tokens = NULL;
	list_parser = NULL;
	list_tokens = divide(cmd, *env);
	// g_v.sig = 0;
	if (list_tokens)
	{
		// print(list_tokens);
		list_parser = parser(list_tokens, *env);
		// parser_print(list_parser);
		execute_main(list_parser, env);
		// printf("\n*********************\n");
	}
	free_token_list(&list_tokens);
	free_parser_list(&list_parser);
	g_v.sig = 1;
}

void  ft_init_variables()
{
    g_v.ex_stu = 0;
    g_v.v_q = 0;
	g_v.flag = 0;
}
int    main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;

    // atexit(l);
	(void)argc;
	(void)argv;
	cmd = NULL;
	env = env_list(envp);
	ft_init_variables();
	ft_signals();
	g_v.sig = 1;
	rl_catch_signals = 0;
	while (1997)
	{
		cmd = readline("minishell ~> ");
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

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*cmd;
// 	t_env	*env;

// 	// atexit(l);
// 	(void)argc;
// 	(void)argv;
// 	cmd = NULL;
// 	env = env_list(envp);
// 	ft_init_variables();
// 	g_v.sig = 1;
// 	ft_signals();
// 	while (1)
// 	{
// 		cmd = readline("minishell ~> ");
// 		if (!cmd)
// 			break ;
// 		add_history(cmd);
// 		if (cmd)
// 			help_main(cmd, &env);
// 		else
// 		{
// 			ft_putendl_fd("exit", 1);
// 			break ;
// 		}
// 		g_v.sig = 1;
// 		free (cmd);
// 	}
// }

// void	help_main(char *cmd, t_env **env)
// {
// 	t_token	*list_tokens;
// 	t_parse	*list_parser;

// 	list_tokens = NULL;
// 	list_parser = NULL;
// 	list_tokens = divide(cmd, *env);
// 	// free_token_list(&list_tokens);
// 	// print(list_tokens);
// 	if (list_tokens)
// 	{
// 		// free_token_list(&list_tokens);
// 		// print(list_tokens);
// 		list_parser = parser(list_tokens, *env);
// 		// parser_print(list_parser);
// 		execute_main(list_parser, env);
// 	// 	printf("\n*********************\n");
// 	}
// 	free_token_list(&list_tokens);
// 	free_parser_list(&list_parser);
// }

// void  ft_init_variables()
// {
// 	g_v.ex_stu = 0;
// 	g_v.v_q = 0;
// 	g_v.sig = 0;
// 	g_v.is_p = 0;
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*cmd;
// 	t_env	*env;

// 	// atexit(l);
// 	(void)argc;
// 	(void)argv;
// 	cmd = NULL;
// 	env = env_list(envp);
// 	ft_init_variables();
// 	g_v.sig = 1;
// 	ft_signals();
// 	while (1)
// 	{
// 		cmd = readline("minishell ~> ");
// 		if (!cmd)
// 			break ;
// 		add_history(cmd);
// 		if (cmd)
// 			help_main(cmd, &env);
// 		else
// 		{
// 			ft_putendl_fd("exit", 1);
// 			break ;
// 		}
// 		free (cmd);
// 	}
// 	g_v.sig = 1;
// }
