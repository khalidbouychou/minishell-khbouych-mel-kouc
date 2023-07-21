/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:53:29 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/21 09:39:13 by khbouych         ###   ########.fr       */
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
void	ft_export(char **arg, t_env *env);
void	ft_print_env(t_env *env);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_strcmp(const char *str1, const char *str2);
#endif