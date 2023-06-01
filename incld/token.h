/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:21 by khbouych          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/31 14:31:39 by khbouych         ###   ########.fr       */
=======
/*   Updated: 2023/06/01 18:27:43 by khbouych         ###   ########.fr       */
>>>>>>> 34c8a337454808cfa3e488d2199ae1640d9817e9
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

enum	e_token_enum
{
	WORD,
	PIPE,
	DQ,
	SQ,
	APPND,
	HERDOC,
	LRED,
	OUTPUT,
	INPUT,
	SPACE,
	VAR
};
/******************************************************************/
typedef struct s_token
{
	char				*content;
	enum e_token_enum	type;
	char				**path;
	int					operator;
	struct s_token		*next;
}t_token;

/************************************************************/
int		ft_strncmp(const char *str1, const char *str2, int n);
void	ft_add_to_list_tokens(t_token **lst_tok, t_token *newtok);
t_token	*divide(char *cmd, t_env *env);
t_token	*ft_listlast(t_token *lst);
int		ft_Qoutes(char *cmd, int *i, int init);
int		ft_Word(char *cmd, int *i, int init);
t_token	*ft_init_token(char *cmd, int i, int count, t_env *env);
#endif