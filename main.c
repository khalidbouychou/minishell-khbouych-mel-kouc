/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/23 19:09:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incld/minishell.h"

int	ft_find_shellvl(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], "SHLVL", 4))
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_set_shlvl(char **str)
{
	char	*res;
	int		val;
	int		i;
	int		j;

	i = ft_find_shellvl(str);
	j = 0;
	if (i == -1)
		return (str);
	while (str[i][j])
	{
		if (str[i][j] == '=')
		{
			val = ft_atoi(&str[i][j + 1]);
			res = ft_itoa(val + 1);
			str[i][j + 1] = res[0];
		}
		j++;
	}
	return (free(res), str);
}

void	help_main(char *cmd, t_env **env)
{
	t_token		*list_tokens;
	t_parse		*list_parser;

	list_tokens = NULL;
	list_parser = NULL;
	list_tokens = divide(cmd, *env);
	g_v.sig = 0;
	if (list_tokens)
	{
		list_parser = parser(list_tokens, *env);
		execute_main(list_parser, env);
	}
	free_token_list(&list_tokens);
	free_parser_list(&list_parser);
	g_v.sig = 1;
}

void	ft_init_variables(void)
{
	g_v.ex_stu = 0;
	g_v._flag = 0;
	g_v.sig = 0;
}

void	ft_track_shlvl(t_env *env)
{
	t_env	*isexist;

	isexist = ft_getenv_node((env), "SHLVL");
	if (!isexist)
		ft_lst_addback(&(env), ft_add_env("SHLVL", "1"));
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;

	// atexit(l);
	(void)argc;
	(void)argv;
	cmd = NULL;
	env = env_list(envp);
	ft_init_variables();
	ft_signals();
	ft_track_shlvl(env);
	g_v.sig = 1;
	while (1997)
	{
		cmd = readline("minishell ~> ");
		add_history(cmd);
		if (cmd)
			help_main(cmd, &env);
		else
		{
			write(1, "exit\n", 6);
			free_env_list(env);
			break ;
		}
		free(cmd);
	}
	return (0);
}
