/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/01 21:07:56 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	count_size(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

char	**list_to_char(t_env *env, char **str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	size = count_size(env);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	while (env)
	{
		str[i] = ft_strjoin(env->key, "=");
		if (env->value)
			str[i] = ft_strjoin(str[i], env->value);
		env = env->next;
		i++;
	}
	str[i] = NULL;
	// free_env_list(env);
	return (str);
}

void	check_fd_exec(t_parse *list_pars)
{
	if (list_pars->fd_input != 0)
	{
		dup2(list_pars->fd_input, STDIN_FILENO);
		close(list_pars->fd_input);
	}
	if (list_pars->fd_output != 1)
	{
		dup2(list_pars->fd_output, STDOUT_FILENO);
		close(list_pars->fd_output);
	}
}

int	simple_not_built(t_parse *list_pars, t_env *env, char **str)
{
	int	id;
	// char	**str;
	// int		i;

	// str = NULL;
	id = fork();
	if (id == -1)
		return (-1);
	else if (id == 0)
	{
		check_fd_exec(list_pars);
		if (execve(list_pars->path, list_pars->arg, str) == -1)
		{
			// perror("Command not found\n");
			if (access(list_pars->arg[0], F_OK) == -1)
				printf("%s: No such file or directory\n", list_pars->arg[0]);
			else if (access(list_pars->arg[0], F_OK & X_OK) == -1)
				printf("%s: command not found\n", list_pars->arg[0]);
			else if (access(list_pars->arg[0], X_OK) == -1)
				printf("minishell: %s: Permission denied\n", list_pars->arg[0]);
			g_stu.ex_stu = 127;
			exit(g_stu.ex_stu);
		}else
			g_stu.ex_stu = 0;
	}
	wait(NULL);
	(void)list_pars;
	(void)env;
	//  str = list_to_char(env, str);
	return (1);
}
