/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:21 by khbouych          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/03 19:16:23 by khbouych         ###   ########.fr       */
=======
/*   Updated: 2023/06/04 16:51:35 by khbouych         ###   ########.fr       */
>>>>>>> ad9309bd7152bce8757237e5e8f564dc5cd7c480
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
	char				*path;
	int					operator;
	struct s_token		*next;
}t_token;

/************************************************************/
int		ft_strncmp(const char *str1, const char *str2, int n);
void	ft_add_to_list_tokens(t_token **lst_tok, t_token *newtok);
t_token	*divide(char *cmd, t_env *env);
t_token	*ft_listlast(t_token *lst);
int		ft_qoutes(char *cmd, int *i, int init);
int		ft_word(char *cmd, int *i, int init);
char	*ft_check_if_cmd_valid(char **path, t_token *tok);
t_token	*ft_init_token(char *cmd, int i, int count, t_env *env);
char	*ft_get_key_from_var(t_token *tok);
#endif