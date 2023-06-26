/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:53:29 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/22 18:13:43 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

# include "incld/minishell.h"

typedef enum s_builtins
{
    ECHO,
    ENV,
    EXIT,
    CD,
    PWD,
    UNSET,
    EXPORT,
} t_bultins;

void    env(t_env *env);

#endif