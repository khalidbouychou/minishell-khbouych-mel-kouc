/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:35:14 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/05/27 18:34:30 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

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

int	main(int argc, char **argv, char **envp)
{
	char	*command;
	t_env	*head;

	(void)argc;
	(void)argv;
	head = env_list(envp);
	// while (head)
	// {
	// 	printf("%s = %s\n",head->key,head->value);
	// 	head = head->next;
	// }
	while (1)
	{
		command = readline("minishell > ");
		if (ft_strlen(command) > 0)
			add_history(command);
		lexer(command);
		free(command);
	}
}
