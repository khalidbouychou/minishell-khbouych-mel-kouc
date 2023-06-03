/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:21 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/03 20:29:00 by mel-kouc         ###   ########.fr       */
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
char	*ft_check_if_cmd_valid(char **path, char *cmd);
t_token	*ft_init_token(char *cmd, int i, int count, t_env *env);

#endif