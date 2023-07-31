/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:35:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/31 16:08:07 by khbouych         ###   ########.fr       */
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
# include <readline/readline.h>
# include "../incld/lexer.h"
# include "../incld/parsing.h"
# include "../incld/token.h"
# include "../incld/builtins.h"
# include "../incld/execution.h"
# include <sys/wait.h>
#include <sys/errno.h>

// for exit status and signals
typedef struct s_glbl
{
	int	ex_stu;
	int	sig;
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
#endif