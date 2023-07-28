/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:45:40 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/27 15:35:13 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ftenv(t_env *env)
{
	ft_print_env(env);
	g_stu.ex_stu = EXIT_SUCCESS;
}
