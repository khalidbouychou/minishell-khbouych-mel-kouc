/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/25 23:37:25 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p)
{
	if (tmp->type == HERDOC)
	{
		if (new_p->fd_input != -4)
			close(new_p->fd_input);
		new_p->f_name = generate_name();
		new_p->fd_input = open(new_p->f_name, O_CREAT, O_WRONLY, 0666);
		if (new_p->fd_input == -1)
			ft_putstr_fd("No such file or directory herdoc\n", 2);
        // else
        //     write_in_herdoc(tmp, new_p);
	}
}
