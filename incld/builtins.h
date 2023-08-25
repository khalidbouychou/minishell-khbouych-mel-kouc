/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:53:29 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/24 18:31:52 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void			norm_check_echo(t_token *ptr, t_token *space);
void			ft_putstr_fd(char *s, int fd);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_sort_keys(t_env *e);
void			ft_print_after_sort(t_env *ee, int fd);
char			*ft_get_key_without_plus(char *key);
char			*ft_get_old_value(t_env *e, char *key);
t_env			*ft_lstlast(t_env *lst);
int				ft_check_n(char *arg);
long long int	ft_atoi(const char *str);
int				ft_arg_digit(char *arg);
int				ft_isdigit(int c);
int				ft_if_key_exist(t_env *e, t_env *node);
void			ft_sort_keys(t_env *e);
void			ft_join_value(t_env *e, t_env *node);
void			ft_exit_output(char *msg, int exit_status, bool _bool);
int				ft_help_export(char **export, t_env *env, int fd);
char			*ft_get_env(t_env *env, char *key);
t_env			*ft_add_env(char *key, char *value);
int				ft_check_by_key(t_env *env, char *key);
void			ft_putnbr(int nb);
void			ft_echo(char **arg, int fd);
void			ft_export(char **export, t_env *env, int fd);
void			ft_unset(t_env **env, char **arg);
void			ft_exit(char **arg, int pipe);
void			ft_env(t_parse *penv, t_env **env);
void			ft_cd(char **cd, t_env *e);
t_env			*ft_getenv_node(t_env *env, char *key);
void			ft_pwd(int fd);
void			ft_cd_(t_env **env, char **ret, char *cmd);
void			ft_init_env(t_env **home, t_env **pwd, t_env **old, t_env *env);
void			update_oldpwd(t_env *env, t_env *old);
void			ft_help_cd(t_env *home, t_env *pwd);
t_token			*check_echo(t_token *tmp, t_token *ptr,
					t_token *space, int *_flag);
#endif