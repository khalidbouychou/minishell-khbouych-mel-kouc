/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/22 11:36:21 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"
#include <signal.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	check_is_delim(char	**str, char *delim, char *buffer, t_parse *new_p)
{
	*str = readline("herdoc> ");
	if (!*str || !ft_strncmp(delim, *str, ft_strlen(*str) + 1))
	{
		if (*buffer)
			write(new_p->fd_input, buffer, ft_strlen(buffer));
		free(*str);
		free(buffer);
		return (0);
	}
	return (1);
}

void	write_in_herdoc(t_token *ptr, t_parse *new_p, t_env *env)
{
	char	*str;
	char	*delim;
	char	*buffer;
	pid_t	pid;
	int		status;

	status = 0;
	ft_init_herdoc(&new_p, &buffer, &delim, &ptr);
	ft_ignoresig();
	pid = fork();
	if (pid == 0)
	{
		ft_defaultsig();
		while (1)
		{
			if (!check_is_delim(&str, delim, buffer, new_p))
				break ;
			fill_buffer(&ptr, &env, &buffer, str);
		}
		exit(0);
	}
	else
		parent_herdoc(new_p, status, pid);
}

void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p, t_env *env)
{
	t_token	*ptr;

	if (tmp->type == HERDOC)
	{
		if (!tmp->prev)
			g_v._flag = 1;
		ptr = tmp->next;
		if (new_p->fd_input != 0)
			close(new_p->fd_input);
		write_in_herdoc(ptr, new_p, env);
	}
}
