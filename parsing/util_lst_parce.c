/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst_parce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:44:39 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/07 11:09:44 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

t_parse	*ft_last_parser(t_parse *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	alloc_arg(t_token *tmp)
{
	int	size;

	size = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		if ((tmp->type == WORD || tmp->type == VAR || tmp->type == SPACE))
			size++;
		tmp = tmp->next;
	}
	return (size);
}

void	add_to_list_parser(t_parse **lst_tok, t_parse *newtok)
{
	t_parse	*last;

	if (*lst_tok == NULL)
		*lst_tok = newtok;
	else
	{
		last = ft_last_parser(*lst_tok);
		last->next = newtok;
	}
}

void	init_struct_parce(t_parse *new_p)
{
	new_p->fd_input = 0;
	new_p->fd_output = 1;
	new_p->f_name = NULL;
	new_p->pid0 = -4;
	// new_p->pid1 = -5;
	new_p->arg = NULL;
}

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	if (s == NULL)
// 		return ;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }