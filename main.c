/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/31 13:58:36 by khbouych         ###   ########.fr       */
=======
/*   Updated: 2023/05/31 13:45:09 by khbouych         ###   ########.fr       */
>>>>>>> adcc01d36e5fd9382b78f685ec8dc46d106358a4
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"


void	ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s = %s\n",env->key,env->value);
		env = env->next;
	}
}

void	print(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}
<<<<<<< HEAD
=======

>>>>>>> adcc01d36e5fd9382b78f685ec8dc46d106358a4
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
		list_tokens = divide(cmd);
		// ft_add_to_list_tokens(list_tokens,ft_new_token(cmd ,env));
		print(divide(cmd));
		// free (cmd);
	}
}
