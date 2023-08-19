/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:52:56 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/19 19:18:06 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_even_keyboard(void)
{
	return (0);
}

void	ft_unlink_close_free(t_parse **new_p)
{
	close((*new_p)->fd_input);
	unlink((*new_p)->f_name);
	free((*new_p)->f_name);
}

void	ft_init_herdoc(t_parse **new_p, char **buf, char **del, char *cnt_d)
{
	ftherdoc_signal(&ft_even_keyboard);
	(*del) = cnt_d;
	(*buf) = NULL;
	(*new_p)->f_name = generate_name();
	(*new_p)->fd_input = open((*new_p)->f_name, O_RDWR
			| O_CREAT | O_TRUNC, 777);
}
