/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:35:14 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/27 16:28:01 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"

t_env	*env_list(char **env)
{
	int		i;
	t_env	*head;

	i = 0;
	head = NULL;
	while (env[i])
	{
		ft_lst_addback(&head, ft_lstnew(env[i]));
		i++;
	}
	return (head);
}

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
	t_env	*head;

	(void)argc;
	(void)argv;
	head = env_list(envp);
	ft_print_env(head);
	while (1)
	{
		cmd = readline("minishell > ");
		if(!cmd)
			return(exit(0),write(1,"exit\n",6));
	}
}
