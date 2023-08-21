/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:53:29 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 23:50:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void		    ft_print_env(t_env *env);
void		    ft_putchar_fd(char c, int fd);
void		    ft_putstr_fd(char *s, int fd);
int			    ft_isalpha(int c);
int			    ft_isalnum(int c);

void		    ft_sort_keys(t_env *e);
void		    ft_print_after_sort(t_env *e);
char		    *ft_get_key_without_plus(char *key);
char		    *ft_get_old_value(t_env *e, char *key);
t_env		    *ft_lstlast(t_env *lst);
int			    ft_check_n(char *arg);
long long int   ft_atoi(const char *str);
int		        ft_arg_digit(char *arg);
int			    ft_isdigit(int c);
int			    ft_if_key_exist(t_env *e, t_env *node);
void		    ft_sort_keys(t_env *e);
void		    ft_join_value(t_env *e, t_env *node);
void		    ft_exit_output(char *msg, int exit_status, bool _bool);
int			    ft_help_export(char **export, t_env *env, int fd);
char		    *ft_get_env(t_env *env, char *key);
t_env		    *ft_add_env(char *key, char *value);
int			    ft_check_by_key(t_env *env, char *key);
void            ft_putnbr(int nb);
/********builtines**************/
void            ft_echo(char **arg, int fd);
void            ft_export(char **export, t_env *env, int fd);
void            ft_unset(t_env **env, char **arg);
void            ft_exit(char **arg, int pipe);
void            ft_env(t_parse *penv, t_env **env);
void            ft_cd(char **cd, t_env *e);
t_env           *ft_getenv_node(t_env *env, char *key);
void            ft_pwd(void);
void            ft_cd_(t_env **env, char **ret, char *cmd);

/*********herdoc***************/

#endif