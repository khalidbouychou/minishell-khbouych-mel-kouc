/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:22:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/02 18:33:50 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../incld/parsing.h"

void	execute_main(t_parse *list_pars, t_env *env);
int		compare_cmd(t_parse *tmp);
char	**list_to_char(t_env *env, char **str);
int		simple_not_built(t_parse *list_pars, t_env *env, char **str);
void	complex_cmd(t_parse *lst_p, t_env *env, char **str);
void	free_char_double(char **str);
void	cmd_in_built(t_parse *list_pars, t_env *env);


#endif