/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:53:29 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/26 00:51:32 by mel-kouc         ###   ########.fr       */
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
void	ft_echo(char **arg, int fd);
void	ft_export(char **export, t_env *env, int fd);
void	ft_print_env(t_env *env);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_get_size_of_list(t_env *env);
void	ft_sort_keys(t_env *e);
void	ft_print_after_sort(t_env *e);
char	*ft_get_key_without_plus(char *key);
char	*ft_get_old_value(t_env *e, char *key);
t_env	*ft_lstlast(t_env *lst);
int	ft_check_n(char *arg);
#endif