/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/13 22:26:53 by khbouych         ###   ########.fr       */
=======
/*   Updated: 2023/06/12 20:19:55 by mel-kouc         ###   ########.fr       */
>>>>>>> 6dab65d712a8cb42e539ff76b2b9c79bc2c70179
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

char *ft_get_value_of_key(char *key , t_env *env)
{
	while (env)
	{
		if(ft_strncmp(key,env->key,ft_strlen(env->key)) == 0)
			return(env->value);
		env = env->next;
	}
	return (NULL);
}

void	ft_expandhelp(char *content , t_env *env)
{
	int	i = 0;
	int	s = 0;
	int	e = 0;
	char *key;
	char *res;
	key = ft_strdup("");
	res = ft_strdup("");
	(void)env;
	while (content[i])
	{
		while (content[i] != '$' && content[i])
			i++;
		s = i + 1;
		while (content[i] != '$' && content[i])
			i++;
		e = i - 1;
		key = malloc(sizeof(char) * ((e - s)));
		key = ft_get_value_of_key(ft_substr(content, s, (size_t)(e - s)),env);
		// res = ft_strjoin(res, key);
		// free(key);
		// printf("%s\n",res);
		i++;
	}
}

void	ft_expander(t_token *tok, t_env *env)
{
	t_token			*tmp;

	tmp = tok;
<<<<<<< HEAD
	(void) env;
	while (tmp)
	{
		if(tmp->type == VAR)
=======
	str = NULL;
	(void)env;
	while (tmp)
	{
		i = 0;
		s = 0;
		e = 0;
		vkey = NULL;
		if (!str)
			str = ft_strdup("");
		// str = ft_strdup(str);
		// i = ft_strchr(tmp->content, '$');
		// if (i != -1)
		if (ft_strchr(tmp->content, '$') != -1)
>>>>>>> 6dab65d712a8cb42e539ff76b2b9c79bc2c70179
		{
			puts("variable");
			ft_expandhelp(tmp->content, env);
		}
		// else
		// 	printf("%s\n",tmp->content);
		tmp = tmp->next;
	}
<<<<<<< HEAD
=======
	printf("key = %s\n", str);
		// printf("key = %s\n", ft_strjoin(str,vkey));
>>>>>>> 6dab65d712a8cb42e539ff76b2b9c79bc2c70179
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
		// ft_expander(list_tokens,env);
		printf("\n*********************\n");
		print(list_tokens);
	}
}
