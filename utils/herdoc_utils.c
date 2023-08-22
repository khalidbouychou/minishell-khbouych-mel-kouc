/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:52:56 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 19:27:20 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_init_herdoc(t_parse **new_p, char **buf, char **del, t_token **ptr)
{
	(*del) = (*ptr)->content;
	(*buf) = NULL;
	(*new_p)->f_name = generate_name();
	(*new_p)->fd_input = open((*new_p)->f_name, O_CREAT | O_WRONLY, 0644);
}

void	parent_herdoc(t_parse *new_p, int status, pid_t pid)
{
	waitpid(pid, &status, 0);
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
