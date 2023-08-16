/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/16 21:31:49 by mel-kouc         ###   ########.fr       */
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
void	ft_init_var_expd(t_exp *var_expd);
char	*expand_sq(char *cnt, t_exp *v, char *r, char *join);
char	*ft_v_k(char *key, t_env *env);

#endif