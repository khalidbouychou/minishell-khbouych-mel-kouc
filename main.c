/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/01 21:01:07 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"

void	ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s = %s\n",env->key, env->value);
		env = env->next;
	}
}

void	print(t_token *lst)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		printf("[cmd]  : %s\n", tmp->content);
		printf("[type] : %u\n", tmp->type);
		printf("[is_op] : %d\n", tmp->operator);
		printf("------------------\n");
		tmp = tmp->next;
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;
	t_token	*list_tokens;

	(void)argc;
	(void)argv;
	env = NULL;
	list_tokens = NULL;
	env = env_list(envp);
	while (1)
	{
		cmd = readline("minishell > ");
		if (!cmd)
			return (printf("exit\n"));
		add_history(cmd);
		list_tokens = divide(cmd, env);
		print(list_tokens);
		parser(list_tokens);
		free (cmd);
	}
}
