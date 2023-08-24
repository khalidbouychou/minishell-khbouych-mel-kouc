/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:22:48 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/24 18:32:08 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../incld/parsing.h"

typedef struct s_pipe
{
	int				fd_p[2];
	struct s_pipe	*next;
	struct s_pipe	*prev;
}	t_pipe;

void	ft_putchar(char c);
void	execute_main(t_parse *list_pars, t_env **env);
int		compare_cmd(t_parse *tmp);
char	**list_to_char(t_env *env, char **str);
int		simple_not_built(t_parse *list_pars, char **str);
void	complex_cmd(t_parse *lst_p, t_env *env, char **str);
void	free_char_double(char **str);
void	cmd_in_built(t_parse *list_pars, t_env **env, int pipe);
int		one_pipe(t_parse *lst_p, t_env *env, char **str);
int		check_fd_exec(t_parse *list_pars);
pid_t	second_child(int fd[2], t_parse *lst_p, t_env *env, char **str);
pid_t	first_child(int fd[2], t_parse *lst_p, t_env *env, char **str);
int		multiple_pipe(t_parse *lst_p, t_env *env, char **str);
void	ft_signals(void);
t_env	*add_env(char *key, char *value);
void	fealed_execve(t_parse *list_pars);
void	close_fd(t_parse *list_pars);
t_pipe	*ft_last_pipe(t_pipe *lst);
t_pipe	*new_pipe(int fd[2]);
void	add_lst_addback(t_pipe **head, t_pipe *new);
t_pipe	*creat_pipe(t_pipe **head);
void	free_pipe(t_pipe *pipe);
void	ft_fok_xok(t_parse *lst);
void	ftstatus(int *status);
pid_t	pid_second_child(t_pipe *tmp, t_parse *lst_p, t_env *env, char **str);
void	wait_id(pid_t pid[], int *status);
#endif