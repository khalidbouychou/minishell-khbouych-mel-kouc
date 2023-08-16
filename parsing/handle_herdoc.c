/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/16 23:14:20 by khbouych         ###   ########.fr       */
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

	if (ft_strchr(str, '$') != -1 && (*ptr)->flag != 1)
		str = ft_expandhelp(str, (*env));
	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, str);
	free(tmp);
	tmp = *buffer;
	*buffer = ft_strjoin(*buffer, "\n");
	free(tmp);
	free(str);
}

void	handle_signal(int sig)
{
	if (sig== SIGINT)
	{
		signal(sig, SIG_IGN);
		ioctl(0, TIOCSTI, "\4");
		signal(sig, handle_signal);
		return ;
	}
	
}
void    write_in_herdoc(t_token *ptr, t_parse *new_p, t_env *env)
{
    char	*str;
    char	*delim;
    char	*buffer;

    delim = ptr->content;
    buffer = NULL;
    new_p->f_name = generate_name();
	g_stu.sig = 0;
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, SIG_DFL);
	while (1)
	{
		str = readline("> ");
		if (!str || !ft_strncmp(delim, str, ft_strlen(str)))
		{
			new_p->fd_input = open(new_p->f_name, O_RDWR | O_CREAT | O_TRUNC, 777);
			if (buffer)
				write(new_p->fd_input, buffer, ft_strlen(buffer));
			return ;
		}
		fill_buffer(&ptr, &env, &buffer, str);
		if (g_stu.sig == 1)
		{
			signal(SIGINT, SIG_DFL);
			g_stu.sig = 0;
			unlink(new_p->f_name);
			new_p->fd_input = open(new_p->f_name, O_RDONLY, 0777);
			if (new_p->fd_input == -1)
				ft_putendl_fd("error in fd herdoc", 2);
			return ;
		}
	}
	close(new_p->fd_input);
	free(new_p->f_name);
}


void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p, t_env *env)
{
	t_token	*ptr;

	if (tmp->type == HERDOC)
	{
		if (!tmp->prev)
			g_stu.flag = 1;
		ptr = tmp->next;
		if (new_p->fd_input != 0)
			close(new_p->fd_input);
		write_in_herdoc(ptr, new_p, env);
	}
}
