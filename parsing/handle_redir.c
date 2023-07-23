/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:20:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/23 22:33:10 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_putstr_fd(char *s, int fd)
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
}

void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p)
{
	if (tmp->type == HERDOC)
	{
		new_p->f_name = tmp->next->content;
		new_p->fd_input = open(new_p->f_name, O_CREAT, O_WRONLY, 0666);
		// if (new_p->fd_herdoc == -1)
		// 	printf("\nerror in herdoc\n");
	}
}

t_token	*ft_handle_oper(t_token *tmp, t_parse *new_p)
{
	// 4 : READ
	// 2 : write
	// 1 : execute
	// perror, strerror
	if (tmp->type == INPUT)
	{
		new_p->f_name = tmp->next->content;
		new_p->fd_input = open("/tmp", O_RDONLY, 0666);
		// if (new_p->fd_input == -1)
		// 	ft_putstr_fd("No such file or directory\n", 2);
	}
	else if (tmp->type == OUTPUT)
	{
		new_p->f_name = tmp->next->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT | O_RDONLY | O_TRUNC, 0666);
		// if (new_p->fd_output == -1)
		// 	ft_putstr_fd("unexpected error\n", 2);
	}
	else
	{
		new_p->f_name = tmp->next->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT | O_RDONLY | O_APPEND, 0666);
		// if (new_p->fd_output == -1)
		// 	ft_putstr_fd("unexpected error\n", 2);
	}
	return (tmp->next);
}

