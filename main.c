/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/12 18:46:47 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incld/minishell.h"

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

// char *ft_get_value_of_key(char *key , t_env *env)
// {
// 	while (env)
// 	{
// 		if(ft_strncmp(key,env->key,ft_strlen(env->key)) == 0)
// 			return(env->value);
// 		env = env->next;
// 	}
// 	return (NULL);
// }

void	ft_expander(t_token *tok, t_env *env)
{
	t_token			*tmp;
	int				i;
	unsigned int	s;
	unsigned int	e;
	char			*vkey;
	char			*str;

	tmp = tok;
	(void)env;
	while (tmp)
	{
		i = 0;
		s = 0;
		e = 0;
		vkey = NULL;
		str = ft_strdup(str);
		if (ft_strchr(tmp->content, '$') != -1)
		{
			i = i + 1;
			while (tmp->content[i])
			{
				s = i;
				while ((tmp->content[i] != '$') && tmp->content[i])
					i++;
				e = i;
				vkey = malloc(sizeof(char) * ((e - s) + 1));
				vkey =  getenv(ft_substr(tmp->content, s, (e - s)));
				printf("ddd\n");
				str = ft_strjoin(str,vkey);
				// printf("i = %d\n",i);
				// printf("s = %d\n",s);
				// printf("e = %d\n",e);
				i++;
			}
		}
		tmp = tmp->next;
	}
		printf("key = %s\n", ft_strjoin(str,vkey));
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
		cmd = readline("shell>>");
		if (!cmd)
			return (printf("error in readline\n"));
		add_history(cmd);
		list_tokens = divide(cmd, env);
		ft_expander(list_tokens,env);
		printf("\n*********************\n");
		print(list_tokens);
	}
}
