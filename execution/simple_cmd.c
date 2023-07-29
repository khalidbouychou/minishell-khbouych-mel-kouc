/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:23:57 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/29 18:22:30 by mel-kouc         ###   ########.fr       */
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
		str[i] = ft_strjoin(str[i], env->value);
		env = env->next;
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	simple_not_built(t_parse *list_pars, t_env *env)
{
	// char	**str;
	// int		i;

	// str = NULL;
	(void)list_pars;
	(void)env;
	// str = list_to_char(env, str);
}
