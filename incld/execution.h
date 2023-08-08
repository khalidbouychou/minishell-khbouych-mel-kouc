/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:22:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/08 09:57:22 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../incld/parsing.h"

void	execute_main(t_parse *list_pars, t_env **env);
int		compare_cmd(t_parse *tmp);
char	**list_to_char(t_env *env, char **str);
int		simple_not_built(t_parse *list_pars, t_env *env, char **str);
void	complex_cmd(t_parse *lst_p, t_env *env, char **str);
void	free_char_double(char **str);
void	cmd_in_built(t_parse *list_pars, t_env **env);
int		one_pipe(t_parse *lst_p, t_env *env, char **str);
int	    check_fd_exec(t_parse *list_pars);
// void	check_fd_exec(t_parse *list_pars);
int		second_child(int fd[2], t_parse *lst_p, t_env *env, char **str);
int		first_child(int fd[2], t_parse *lst_p, t_env *env, char **str);
int		multiple_pipe(t_parse *lst_p, t_env *env, char **str);

void	ft_signals(void);
t_env	*add_env(char *key, char *value);
void	fealed_execve(t_parse *list_pars);
#endif