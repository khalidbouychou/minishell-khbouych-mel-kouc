/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/22 02:19:44 by mel-kouc         ###   ########.fr       */
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

void	fill_buffer(t_token **ptr, t_env **env, char **buffer, char *str)
{
	char	*tmp;

	if (ft_strchr(str, '$') != -1 && (*ptr)->_flag != 1)
		str = ft_expandhelp(str, (*env));
	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, str);
	free(tmp);
	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, "\n");
	free(tmp);
	free(str);
}
void	parent_herdoc(t_parse *new_p, int status)
{
	// waitpid(*pid, status, 0);
	ft_signals();
	if (status == 2)
	{
		write(1, "\n", 1);
		g_v.sig = -1;
	}
	close(new_p->fd_input);
	new_p->fd_input = open(new_p->f_name, O_RDONLY, 0644);
	unlink(new_p->f_name);
	free(new_p->f_name);
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

	delim = ptr->content;
	buffer = NULL;
	new_p->f_name = generate_name();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	new_p->fd_input = open(new_p->f_name, O_WRONLY | O_CREAT, 0644);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		while (1)
		{
			if (!check_is_delim(&str, delim, buffer, new_p))
				break ;
			fill_buffer(&ptr, &env, &buffer, str);
		}
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	parent_herdoc(new_p, status);
}

void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p, t_env *env)
{
	t_token	*ptr;

	(void)env;
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
