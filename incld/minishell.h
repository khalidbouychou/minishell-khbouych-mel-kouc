/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:35:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/24 18:32:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include "../incld/lexer.h"
# include "../incld/token.h"
# include "../incld/parsing.h"
# include "../incld/builtins.h"
# include "../incld/execution.h"

typedef struct s_glbl
{
	int		_flag;
	int		ex_stu;
	int		sig;
	char	*current_pwd;
}	t_glbl;

t_glbl	g_v;

char	*findpathvalue(t_env *head);
void	ft_track_shlvl(t_env *env);
void	ft_init_variables(void);
void	ft_main_norm(t_env *env);
t_env	*ft_lstnew(char *env);
void	ft_lst_addback(t_env **head, t_env *new);
t_env	*env_list(char **env);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
void	free_parser_list(t_parse **list);
void	env_not_exist(int i, char **key, char **value);
int		ft_strcmp(const char *str1, const char *str2);
void	ft_ignoresig(void);
void	ft_defaultsig(void);
char	**ft_set_shlvl(char **str);
int		ft_find_shellvl(char **str);
#endif
