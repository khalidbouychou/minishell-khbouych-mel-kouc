/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl_multi_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:28:30 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/11 21:40:28 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

t_pipe	*ft_last_pipe(t_pipe *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_pipe	*new_pipe(int fd[2])
{
	t_pipe	*new_pipe;

	new_pipe = malloc(sizeof(t_pipe));
	if (!new_pipe)
		return (NULL);
	new_pipe->fd_p[0] = fd[0];
	new_pipe->fd_p[1] = fd[1];
	new_pipe->next = NULL;
	new_pipe->prev = NULL;
	return (new_pipe);
}

void	add_lst_addback(t_pipe **head, t_pipe *new)
{
	t_pipe	*last;

	if (!head || !new)
		return ;
	else if (*head == 0)
		*head = new;
	else
	{
		last = ft_last_pipe(*head);
		last->next = new;
		new->prev = last;
	}
}

t_pipe	*creat_pipe(t_pipe **head)
{
	int		fd[2];
	t_pipe	*tmp;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (NULL);
	}
	add_lst_addback(head, new_pipe(fd));
	tmp = *head;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}
