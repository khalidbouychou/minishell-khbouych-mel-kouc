/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/13 20:41:04 by mel-kouc         ###   ########.fr       */
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
void	fill_buffer(t_token *ptr, t_env *env, char *buffer, char *str)
{
	char	*tmp;

	if (ft_strchr(str, '$') != -1 && ptr->flag != 1)
		str = ft_expandhelp(str, env);
	tmp = buffer;
	buffer = ft_strjoin(buffer, str);
	free(tmp);
	tmp = buffer;
	buffer = ft_strjoin(buffer, "\n");
	free(tmp);
	free(str);
}

void	write_in_herdoc(t_token *ptr, t_parse *new_p, t_env *env)
{
	char	*str;
	char	*delim;
	char	*buffer;
	char	*tmp;

	delim = ptr->content;
	buffer = ft_strdup("");
	new_p->f_name = generate_name();
	while (1)
	{
		str = readline("> ");
		if (!ft_strncmp(delim, str, ft_strlen(str)))
		{
			new_p->fd_input = open(new_p->f_name, O_WRONLY | O_CREAT, 0644);
			if (*buffer)
				write(new_p->fd_input, buffer, ft_strlen(buffer));
			free(buffer);
			free(str);
			break ;
		}
		// fill_buffer(ptr, env, buffer, str);
		if (ft_strchr(str, '$') != -1 && ptr->flag != 1)
			str = ft_expandhelp(str, env);
		tmp = buffer;
		buffer = ft_strjoin(buffer, str);
		free(tmp);
		tmp = buffer;
		buffer = ft_strjoin(buffer, "\n");
		free(tmp);
		free(str);
	}
	close(new_p->fd_input);
	new_p->fd_input = open(new_p->f_name, O_RDONLY, 0644);
	unlink(new_p->f_name);
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
