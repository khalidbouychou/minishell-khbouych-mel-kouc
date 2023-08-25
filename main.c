/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:07:26 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/24 18:39:19 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incld/minishell.h"

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

void	ft_track_shlvl(t_env *env)
{
	t_env	*isexist;

	isexist = ft_getenv_node((env), "SHLVL");
	if (!isexist)
		ft_lst_addback(&(env), ft_add_env("SHLVL", "1"));
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
		if (g_v.sig != -1)
			execute_main(list_parser, env);
	}
	free_token_list(&list_tokens);
	free_parser_list(&list_parser);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_env	*env;

	(void)argc;
	(void)argv;
	cmd = NULL;
	env = env_list(envp);
	ft_main_norm(env);
	while (1997)
	{
		cmd = readline("minishell-> ");
		add_history(cmd);
		if (!cmd)
		{
			write(1, "exit\n", 6);
			free_env_list(env);
			break ;
		}
		else
			help_main(cmd, &env);
		g_v.sig = 0;
		g_v._flag = 0;
		free(cmd);
	}
	return (0);
}
