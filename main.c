/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/30 21:36:59 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"


void ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s = %s\n",env->key,env->value);
		env = env->next;
	}
}

void print(t_token *lst)
{
	t_token *tmp;
	tmp = lst;
	while (tmp)
	{
		printf("cmd == > %s\n",tmp->content);
		printf("\n-----------\n");
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*cmd;
	t_env	*env=NULL;
	t_token *list_tokens =NULL;
	env = env_list(envp);
	while (1)
	{
		cmd = readline("minishell > ");
		if(!cmd)
			return(exit(0),write(1,"exit\n",6));
		add_history(cmd);
		list_tokens = divide(cmd);
		// ft_add_to_list_tokens(list_tokens,ft_new_token(cmd ,env));
		// print(divide(cmd));
	}
}
