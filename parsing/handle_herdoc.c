/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/15 17:46:07 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

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

void	write_in_herdoc(t_token *ptr, t_parse *new_p, t_env *env)
{
	char	*str;
	char	*delim;
	char	*buffer;

	delim = ptr->content;
	buffer = NULL;
	new_p->f_name = generate_name();
	int pid;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		while (1)
		{
			str = readline("> ");
			if (!str || !ft_strncmp(delim, str, ft_strlen(str)))
			{
				new_p->fd_input = open(new_p->f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (buffer)
					write(new_p->fd_input, buffer, ft_strlen(buffer));
				break ;
			}
			if (ft_strchr(str, '$') != -1 && ptr->flag != 1)
				str = ft_expandhelp(str, env);
			buffer = ft_strjoin(buffer, str);
			buffer = ft_strjoin(buffer, "\n");
		}
		close(new_p->fd_input);
		new_p->fd_input = open(new_p->f_name, O_RDONLY | O_TRUNC, 0644);
		unlink(new_p->f_name);
	}
	else
	{
		ft_signals();
		waitpid(pid, NULL, 0);
	}
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
