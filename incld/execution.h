/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:22:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/29 17:51:17 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../incld/parsing.h"

void	execute_main(t_parse *list_pars, t_env *env);
int		compare_cmd(t_parse *tmp);
void	simple_not_built(t_parse *list_pars, t_env *env);
char	**list_to_char(t_env *env, char **str);

#endif