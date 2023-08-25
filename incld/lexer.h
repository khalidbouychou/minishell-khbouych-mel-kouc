/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/25 16:23:59 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../incld/minishell.h"
# include "../incld/token.h"

typedef struct s_variable
{
	int		i;
	int		s;
	int		e;
	char	*r;
}t_exp;

void	ft_expander(t_token *tok, t_env *env);
void	ft_init_var_expd(t_exp *var_expd, int *dollar);
char	*expand_sq(char *cnt, t_exp *v, char *r, char *join);
char	*ft_v_k(char *key, t_env *env);
void	expand_digit(char *cnt, t_exp *v);
char	*ft_itoa(int nbr);
void	sub_expand_value(char *cnt, t_exp *v, t_env *env, int *echo_flag);
void	not_isalnum(char *cnt, t_exp *v);
void	join_after_exp(char *cnt, t_exp *v);
char	*return_v_r(char *cnt, t_exp *v);
char	*ft_trim_spaces_echo(char *tmp);
void	help_ft_test(char	*tmp, char *cnt, size_t *i, char *str);
char	*ft_norm_expand(char *cnt, t_exp v);

#endif