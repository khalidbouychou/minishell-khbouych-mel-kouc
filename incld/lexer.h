/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/19 18:38:56 by khbouych         ###   ########.fr       */
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
void	ft_strcpy(char *dest, char *src);
#endif