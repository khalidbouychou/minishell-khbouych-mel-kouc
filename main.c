/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/16 02:06:23 by khbouych         ###   ########.fr       */
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
		// printf("[is_op] : %d\n", tmp->operator);
		// printf("[path] : %s\n", tmp->path);
		printf("------------------\n");
		tmp = tmp->next;
		i++;
	}
}

void	l(void)
{
	system("leaks minishell");
}

char	*ft_get_value_of_key(char *key, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(key, env->key, ft_strlen(env->key)) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*ft_expandhelp(char *content, t_env *env)
{
	int		i;
	int		s;
	int		e;
	char	*res;
	char	*key;

	i = 0;
	s = 0;
	e = 0;
	res = NULL;

	while (content[i])
	{
		while (content[i] != '$' && content[i])
			i++;
		s = i + 1;
		while (content[i] != '$' && content[i])
			i++;
		e = i - 1;
		i++;
		key = ft_get_value_of_key(ft_substr(content, s, (e - s)), env);
		res = ft_strjoin(res, key);
	}
	return (res);
}

void	ft_expander(t_token *tok, t_env *env)
{
	char			*res;
	t_token			*tmp;

	res = NULL;
	tmp = tok;

	while (tmp)
	{
		if (tmp->type == VAR)
			res = ft_strjoin(res, ft_expandhelp(tmp->content, env));
		tmp = tmp->next;
	}
	printf("res %s\n",res);
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
		// print(list_tokens);
	}
}
