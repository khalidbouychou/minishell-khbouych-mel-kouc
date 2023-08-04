/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/04 20:23:01 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"
// #include <errno.h>

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

void	fealed_execve(t_parse *list_pars)
{
	if (ft_strchr(list_pars->arg[0], '/') != -1)
	{
		if (access(list_pars->path, F_OK) == -1)
		{
			ft_putstr_fd("No such file or directory\n", 2);
			g_stu.ex_stu = 127;
		}
		else if (access(list_pars->path, X_OK) == -1)
		{
			ft_putstr_fd("Permission denied\n", 2);
			g_stu.ex_stu = 126;
		}
		else
		{
			ft_putstr_fd("is a directory\n", 2);
			g_stu.ex_stu = 126;
		}
	}
	else
	{
		if (access(list_pars->path, F_OK) == -1)
		{
			ft_putstr_fd("command not found\n", 2);
			g_stu.ex_stu = 127;
		}
		else
			g_stu.ex_stu = 0;
	}
}

int	simple_not_built(t_parse *list_pars, t_env *env, char **str)
{
	pid_t	id ;
	int		status;

	id = fork();
	if (id == -1)
		return (-1);
	else if (id == 0)
	{
		check_fd_exec(list_pars);
		if (execve(list_pars->path, list_pars->arg, str) == -1)
			fealed_execve(list_pars);
	}
	waitpid(id, &status, 0);
	if (status == 256)
		g_stu.ex_stu = 1;
	else if (status == 0)
		g_stu.ex_stu = 0;
	// printf("status = %d\n", status);
	// printf("id  = %d\n", id);
	(void)env;
	return (1);
}
