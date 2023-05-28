/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/28 21:30:06 by khbouych         ###   ########.fr       */
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
int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;
	t_lexer *lexer;
	(void)argc;
	(void)argv;
	env = env_list(envp);
	while (1)
	{
		cmd = readline("minishell > ");
		if(!cmd)
			return(exit(0),write(1,"exit\n",6));
		add_history(cmd);
		lexer = ft_create_token(cmd,env);
		printf("%s\n",lexer->path);
	}
}
