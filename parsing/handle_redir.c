/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:20:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/22 23:24:58 by mel-kouc         ###   ########.fr       */
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

// void	ft_handle_oper(t_token *tmp, t_parse *new_p)
// {
// 	int	fd;

// // 4 : READ
// // 2 : write
// // 1 : execute
// 	fd = -10;
// 	// if (tmp->type == HERDOC)
// 	new_p->name = tmp->next->content;
// 	if (tmp->type == INPUT)
// 	{
// 		fd = open(new_p->name, O_RDONLY, 0666);
// 		if (fd < 0)
// 			ft_putstr_fd("unexpected error\n", 2)
// 	}
// 	else if (tmp->type == OUTPUT)
// 	{
// 		fd = open(new_p->name, O_CREAT | O_RDONLY | O_TRUNC);
// 	}
// 	else if (tmp->type == APPND)
// 	{
// 		fd = open(new_p->name, O_CREAT | O_RDONLY | O_APPEND);
// 	}
// }

