/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:47:06 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/10 21:47:12 by mel-kouc         ###   ########.fr       */
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
	// new_pipe->fd[]
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

int	creat_pipe(t_pipe **head)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	add_lst_addback(head, new_pipe(fd));
	return (1);
}

int	middle_pipes(t_pipe *head, t_parse *lst_p, t_env *env, char **str)
{
	t_pipe	*tmp;
	int		i;

	i = 0;
	tmp = head;
	lst_p->pid0 = fork();
	if (lst_p->pid0 == -1)
		return (-1);
	else if (lst_p->pid0 == 0)
	{
		close(tmp->fd_p[1]);
		i = check_fd_exec(lst_p);
		if (i != 1)
		{
			dup2(tmp->fd_p[0], STDIN_FILENO);
			if (i == 0)
			{
				close(tmp->next->fd_p[0]);
				dup2(tmp->next->fd_p[1], STDOUT_FILENO);
				close(tmp->next->fd_p[1]);
			}
		}
		close(tmp->fd_p[0]);
		if (compare_cmd(lst_p))
		{
			lst_p->fd_output = 1;
			cmd_in_built(lst_p, &env);
			exit(g_stu.ex_stu);
		}
		else if (execve(lst_p->path, lst_p->arg, str) == -1)
		{
			fealed_execve(lst_p);
			exit(g_stu.ex_stu);
		}
	}
	return (1);
}

void	ft_list_pipe(t_pipe **head, t_parse *lst_p)
{
	t_parse	*tmp;

	tmp = lst_p;
	while (tmp)
	{
		if (tmp->next)
			creat_pipe(head);
		tmp = tmp->next;
	}
}

int	multiple_pipe(t_parse *lst_p, t_env *env, char **str)
{
	t_pipe	*head;
	int		i;
	int		status;
	// t_parse	*lst_p;

	i = 0;
	head = NULL;
	ft_list_pipe(&head, lst_p);
	while (lst_p)
	{
		// creat_pipe(&head);
		if (i == 0)
			first_child(head->fd_p, lst_p, env, str);
		else if (lst_p->next)
			middle_pipes(head, lst_p, env, str);
		else if (!lst_p->next)
			second_child(head->fd_p, lst_p, env, str);
		waitpid(lst_p->pid0, &status, 0);
		lst_p = lst_p->next;
		if (head->next)
			head = head->next;
		i = 1;
	}
	// second_child(fd, lst_p->next, env, str)
	return (1);
}
