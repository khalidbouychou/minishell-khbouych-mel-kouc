/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:35:45 by mel-kouc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/28 16:34:01 by mel-kouc         ###   ########.fr       */
=======
/*   Updated: 2023/05/29 14:51:11 by khbouych         ###   ########.fr       */
>>>>>>> fdaf2a1658950bc0693eacb7b5def944b6df69f8
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
<<<<<<< HEAD
=======
# include <stdio.h>
#include <string.h>
>>>>>>> fdaf2a1658950bc0693eacb7b5def944b6df69f8
# include <readline/readline.h>
# include "../incld/lexer.h"
# include "../incld/parsing.h"
# include "../incld/token.h"

//----------------------* struct env *----------------------//

int		ft_strchr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
t_env	*ft_lstnew(char *env);
void	ft_lst_addback(t_env **head, t_env *new);
<<<<<<< HEAD

char	*lexer(char *commande);

=======
t_env	*env_list(char **env);
/*******************************/
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
/****************/
t_token *ft_new_token(char *cmd , t_env *env);
>>>>>>> fdaf2a1658950bc0693eacb7b5def944b6df69f8
#endif