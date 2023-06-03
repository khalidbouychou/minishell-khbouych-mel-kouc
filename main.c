/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/03 16:59:03 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"

void	print(t_token *lst)
{
	t_token	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		printf("[cmd]  : %s\n", tmp->content);
		printf("[type] : %u\n", tmp->type);
		printf("[is_op] : %d\n", tmp->operator);
		printf("[path] : %s\n", tmp->path);
		printf("------------------\n");
		tmp = tmp->next;
		i++;
	}
}

void	l(void)
{
	system("leaks minishell");
}

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
		cmd = readline("minishell----> ");
		if (!cmd)
			return (printf("exit\n"));
		add_history(cmd);
		list_tokens = divide(cmd, env);
		print(list_tokens);
	}
}
