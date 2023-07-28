/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:53:29 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/27 18:36:08 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef enum s_builtins
{
	ECHO,
	ENV,
	EXIT,
	CD,
	PWD,
	UNSET,
	EXPORT,
}	t_builtins;

// void    env(t_env *env);
void		ft_echo(char **arg, int fd);
void		ft_export(char **export, t_env *env, int fd);
void		ft_print_env(t_env *env);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_strcmp(const char *str1, const char *str2);
void		ft_sort_keys(t_env *e);
void		ft_print_after_sort(t_env *e);
char		*ft_get_key_without_plus(char *key);
char		*ft_get_old_value(t_env *e, char *key);
t_env		*ft_lstlast(t_env *lst);
int			ft_check_n(char *arg);
long long	ft_atoi(const char *str);
int			ft_check_arg_is_digit(char *arg);
int			ft_isdigit(int c);
int			ft_if_key_exist(t_env *e, t_env *node);
void		ft_sort_keys(t_env *e);
void		ft_unset(t_env *env, char **arg);
void		ft_join_value(t_env *e, t_env *node);
void		ft_exit(char **arg);
int			ft_check_overflow(char *arg);
#endif