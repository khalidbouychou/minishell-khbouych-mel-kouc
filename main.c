/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/30 18:49:25 by mel-kouc         ###   ########.fr       */
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
	// int i = 0;
	tmp = lst;
	// while (tmp)
	// {
		printf("tokens == > %s\n",tmp->content);
	// 	tmp = tmp->next;
	// }
}


// char **ft_split_cmd(char *cmd , char c)
// {
//     int s = 0;
//     int e = 0;
// 	char **cg;
// 	int i = 0;
// 	int x = 0;
// 	while (cmd[i] && cmd[i] == 32)
// 		i++;
// 	while (cmd[i])
// 	{
// 		s = i;
// 		if(cmd[i] && cmd[i] != c)
// 			x++;
// 		while(cmd[i] && cmd[i] != 32 && cmd[i] != c )
// 			i++;
// 	}
// 	cg = malloc(sizeof(char *) * (x + 1));
// 	i = 0;
// 	x = 0;
// 	while (cmd[i])
// 	{
// 		while((cmd[i] && cmd[i]) != c || cmd[i] == 32)
// 			i++;
// 		s = i;
// 		while(cmd[i] && cmd[i] != 32 && cmd[i] != c )
// 			i++;
// 			e = i - 1;
// 			if(s < e)
// 			{
// 				cg[x] =malloc(sizeof(char) * (e - s) + 1);
// 				ft_strncpy(cg[x++],&cmd[i],e - s);
// 			}
// 	}
// 	cg[x] = NULL;
// 	return cg;
// }

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*cmd;
	t_env	*env=NULL;
	t_token **list_tokens =NULL;
	list_tokens = (t_token **)malloc(sizeof(t_token *));
	env = env_list(envp);
	while (1)
	{
		cmd = readline("minishell > ");
		if(!cmd)
			return(exit(0),write(1,"exit\n",6));
		add_history(cmd);
		list_tokens = divide(cmd);
		// ft_add_to_list_tokens(list_tokens,ft_new_token(cmd ,env));
		// print(*list_tokens);
	}
}
