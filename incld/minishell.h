/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:35:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/16 09:54:37 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../incld/lexer.h"
# include "../incld/parsing.h"
# include "../incld/token.h"
# include "../incld/builtins.h"
# include "../incld/execution.h"
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/stat.h>
 #include <signal.h>

// for exit status and signals
typedef struct s_glbl
{
	int		ex_stu;
	int		sig;
	char	*current_pwd;
	int		flag;
	int		v_q;
	int is_p;
}	t_glbl;

t_glbl	g_stu;
//----------------------* struct env *----------------------//
t_env	*ft_lstnew(char *env);
void	ft_lst_addback(t_env **head, t_env *new);
t_env	*env_list(char **env);
/**************************************************************/
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
/**************************************************************/
void	ft_print_env(t_env *env);
void	ft_putendl_fd(char *s, int fd);
void	sig_handler(int signal);

void	print(t_token *lst);
void	free_parser_list(t_parse **list);
void	env_not_exist(int i, char **key, char **value);

#endif
