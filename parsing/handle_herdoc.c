/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/26 23:28:45 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

// char	*expande_herdoc(char *var)
// {
	
// }
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
	// new_p->fd_input = open(new_p->f_name, O_CREAT, O_WRONLY, 0666);
	if (new_p->fd_input == -1)
		ft_putstr_fd("No such file or directory herdoc\n", 2);
	else
	{
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
			// ft_putendl_fd(str, new_p->fd_input);
			buffer = ft_strjoin(buffer, str);
			buffer = ft_strjoin(buffer, "\n");
		}
	}
	close(new_p->fd_input);
	printf("%d\n", new_p->fd_input);
}

void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p, t_env *env)
{
	t_token	*ptr;

	ptr = tmp->next;
	if (tmp->type == HERDOC)
	{
		if (new_p->fd_input != -4)
			close(new_p->fd_input);
		write_in_herdoc(ptr, new_p, env);
		// new_p->f_name = generate_name();
		// new_p->fd_input = open(new_p->f_name, O_CREAT, O_WRONLY, 0666);
		// if (new_p->fd_input == -1)
		// 	ft_putstr_fd("No such file or directory herdoc\n", 2);
		// else
		// 	write_in_herdoc(ptr, new_p);
	}
}
