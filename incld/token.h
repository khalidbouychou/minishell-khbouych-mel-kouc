/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:21 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/25 16:04:37 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "../incld/minishell.h"
# include "../incld/token.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

enum	e_token_enum
{
	VAR,
	WORD,
	PIPE,
	DQ,
	SQ,
	APPND,
	HERDOC,
	LRED,
	OUTPUT,
	INPUT,
	SPC,
	_TAB,
	FIL,
};
/******************************************************************/
typedef struct s_token
{
	char				*content;
	enum e_token_enum	type;
	char				*path;
	int					operator;
	struct s_token		*next;
	struct s_token		*prev;
	int					_flag;
	int					echo_flag;
}t_token;

/************************************************************/
void	ft_add_to_list_tokens(t_token **lst_tok, t_token *newtok);
int		ft_qoutes(char *cmd, int *i, int init);
int		ft_word(char *cmd, int *i, int init);
char	*ft_check_if_cmd_valid(char **path, char *str);
t_token	*ft_init_token(char *cmd, int i, int count);
int		check_list(t_token **lst, t_env *env);
int		successive_oper(t_token *list_tokens);
int		oper_in_end(t_token	*list_tokens);
int		check_close_q(t_token *tmp);
int		check_pipe(t_token	*list_tokens);
int		check_spases(t_token *tmp);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strsearch(const char *s, int c);
void	rm_node_white_space(t_token **lst);
void	util_between_word_var(t_token *ptr, t_token	*tmp);
void	check_cmd(t_token **lst);
void	ft_tolower(char *str);
t_token	*echo_and_n(t_token *ptr, t_token *space);
void	util_between_oper(t_token *tmp, t_token	*right_op, t_token	*left_op);
int		check_spases(t_token *tmp);
void	space_after_cmd(t_token **lst);
void	free_token_list(t_token **lst);
void	free_env_list(t_env *env);
int		check_operator(t_token	**list_tokens);
int		check_quotes(t_token **list_tokens);
t_token	*divide(char *cmd, t_env *env);
t_token	*ft_listlast(t_token *lst);
void	ft_set_oper(t_token *tok);
void	check_herdoc_quotes(t_token *lst);
char	*ft_expandhelp(char *cnt, t_env *env, int *echo_flag);
void	operator_right(t_token *tmp, t_token *right_op);
void	help_lixer_list(char *str, t_token *tmp, t_token *ptr);

#endif