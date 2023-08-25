/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/25 16:02:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../incld/token.h"

typedef struct s_parse
{
	int				fd_input;
	int				fd_output;
	char			*f_name;
	char			**arg;
	struct s_parse	*next;
	char			*path;
	int				_flag_herd;
	pid_t			pid0;
}	t_parse;

char	*ft_itoa(int nbr);
t_parse	*parser(t_token	*list_tokens, t_env *env);
t_parse	*ft_last_parser(t_parse *lst);
int		alloc_arg(t_token *tmp);
void	init_struct_parce(t_parse *new_p);
void	add_to_list_parser(t_parse **lst_tok, t_parse *newtok);
t_token	*ft_handle_oper(t_token *tmp, t_parse *new_p, t_env *env, int *_flag);
void	ft_searsh_herdoc(t_token *tmp, t_parse *new_p, t_env *env);
void	ft_putstr_fd(char *s, int fd);
char	*generate_name(void);
char	*ft_get_path(t_env *env, char *str);
void	add_if_not_found(t_env **head, int i);
int		compare_path(char *tmp);
void	ft_init_herdoc(t_parse **new_p, char **del, t_token **ptr);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_child_sig_handler(int sig);
void	parent_herdoc(t_parse *new_p, int status, pid_t pid);
void	fill_buffer(t_token **ptr, t_env **env, char **buffer, char *str);
void	check_cmd(t_token **lst);
#endif