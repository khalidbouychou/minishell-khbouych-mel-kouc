/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:21 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/17 12:56:45 by khbouych         ###   ########.fr       */
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
	VAR,//0
	WORD,//1
	PIPE,//2
	DQ,//3
	SQ,//4
	APPND,//5
	HERDOC,//6
	LRED,//7
	OUTPUT,//8
	INPUT,//9
	SPC,//10
	_TAB,//11
	FIL,//12
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
	int					flag;
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
char	*ft_expandhelp(char *cnt, t_env *env);
void	operator_right(t_token *tmp, t_token *right_op);
void	help_lixer_list(char *str, t_token *tmp, t_token *ptr);

#endif