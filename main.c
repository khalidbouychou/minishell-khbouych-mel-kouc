/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/17 21:56:01 by mel-kouc         ###   ########.fr       */
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
	printf("\n------------------\n");
	while (tmp && tmp->content)
	{
		printf("[cmd]  : |%s|\n", tmp->content);
		printf("[type] : %d\n", tmp->type);
		printf("[is_op] : %d\n", tmp->operator);
		// printf("[path] : %s\n", tmp->path);
		printf("------------------\n");
		tmp = tmp->next;
		i++;
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

	// atexit(l);
	(void)argc;
	(void)argv;
	env = NULL;
	list_tokens = NULL;
	env = env_list(envp);
	while (1)
	{
		cmd = readline("minishell ~> ");
		if (*cmd)
		{
			add_history(cmd);
			list_tokens = divide(cmd, env);
			print(list_tokens);
			parser(list_tokens);
			printf("\n*********************\n");
		}
		free (cmd);
	}
}
