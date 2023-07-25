/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/26 00:21:35 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"
#include <sys/types.h>

void	ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s = %s \n", env->key, env->value);
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
	printf("\n------------------------------------\n");
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
	
	printf("\n------------------------------------\n");
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

// void	ft_handel_signal(int signal)
// {
// 	if (signal == SIGQUIT)
// 	{
// 		ft_putchar_fd('\r', 1);
// 		rl_on_new_line();
// 	}
// 	else if (signal == SIGINT)
// 	{
// 		ft_putchar_fd('\n', 1);
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }

// void 	ft_menu_bultins(char *cmd)
// {
// 	if(ft_strncmp(cmd, "echo",ft_strlen(cmd)) == 0)
// 		env();
// }

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
	env = NULL;
	list_tokens = NULL;
	list_parser = NULL;
	env = env_list(envp);
	// ft_export(argv,env);
	// ft_echo(argv,1);
	while (1)
	{
		cmd = readline("minishell ~> ");
		if (*cmd)
		{
			add_history(cmd);
			list_tokens = divide(cmd, env);
			// print(list_tokens);
			list_parser = parser(list_tokens);
			printf("\n***** $$$$$$$$$$$$$$ *****\n");
			execute_main(list_parser);
			printf("\n*********************\n");
			// parser_print(list_parser);
		}
		free (cmd);
	}
}
