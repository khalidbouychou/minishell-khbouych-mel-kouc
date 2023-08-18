/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/18 16:10:08 by khbouych         ###   ########.fr       */
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

void    write_in_herdoc(t_token *ptr, t_parse *new_p, t_env *env)
{
    char	*str;
    char	*delim;
    char	*buffer;

	ft_init_herdoc(&new_p, &buffer, &delim, ptr->content);
	while (1)
	{
		str = readline("herdoc : ");
		if (!str || !ft_strcmp(delim, str))
		{
			if (buffer)
				write(new_p->fd_input, buffer, ft_strlen(buffer));
			free(buffer);
			break;
		}
		fill_buffer(&ptr, &env, &buffer, str);
		if (g_v.sig == -1 || new_p->fd_input == -1)
		{
			break ;
		}
	}
	ft_unlink_close_free((&new_p));
	new_p->fd_input = open(new_p->f_name, O_RDONLY | O_TRUNC, 0777);
	return ;
}


void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p, t_env *env)
{
	t_token	*ptr;

	if (tmp->type == HERDOC)
	{
		g_v.sig = 0;
		if (!tmp->prev)
			g_v.flag = 1;
		ptr = tmp->next;
		if (new_p->fd_input != 0)
			close(new_p->fd_input);
		write_in_herdoc(ptr, new_p, env);
	}
}
