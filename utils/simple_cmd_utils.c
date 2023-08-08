/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:48:50 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/08 16:06:55 by mel-kouc         ###   ########.fr       */
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

void	ft_fok_xok(t_parse *lst)
{
	if (ft_strchr(lst->arg[0], '/') != -1)
	{
		if (access(lst->path, F_OK) == -1)
		{
			ft_putstr_fd("No such file or directory\n", 2);
			g_stu.ex_stu = 127;
		}
		else if (access(lst->path, X_OK) == -1)
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
}

void	fealed_execve(t_parse *list_pars)
{
	if (ft_strchr(list_pars->arg[0], '/') != -1)
		ft_fok_xok(list_pars);
	else
	{
		if (!ft_strcmp(list_pars->arg[0], "")
			|| access(list_pars->path, F_OK) == -1)
		{
			ft_putstr_fd("command not found\n", 2);
			g_stu.ex_stu = 127;
		}
		else
			g_stu.ex_stu = 0;
	}
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
	free_env_list(env);
	return (str);
}
