/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/03 19:37:13 by khbouych         ###   ########.fr       */
=======
/*   Updated: 2023/06/03 20:48:42 by khbouych         ###   ########.fr       */
>>>>>>> ad9309bd7152bce8757237e5e8f564dc5cd7c480
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*ft_check_if_cmd_valid(char **path, t_token *tok)
{
	int		i;
	char	*p;

	p = NULL;
	i = 0;
	while (path[i])
	{
		p = ft_strjoin(path[i], "/");
		p = ft_strjoin(p, tok->content);
		if (access(p, X_OK | F_OK) == 0)
			return (p);
		i++;
	}
	return (NULL);
}

void	ft_add_to_list_tokens(t_token **lst_tok, t_token *newtok)
{
	t_token	*last;

	if (*lst_tok == NULL)
		*lst_tok = newtok;
	else
	{
		last = ft_listlast(*lst_tok);
		last->next = newtok;
	}
}

int	ft_count_alloc(char *cmd, int i, t_token **list, t_env *env)
{
	int	count;
	int	init;

	count = 0;
	init = i;
	if ((cmd[i] == '>' && cmd[i + 1] == '>') || (cmd[i] == '<'
			&& cmd[i + 1] == '<'))
	{
		count = 2;
		i = i + count;
	}
	else if (cmd[i] == '|' || cmd[i] == ' ' || cmd[i] == '>' || cmd[i] == '<')
	{
		count = 1;
		i = i + count;
	}
	else if ((cmd[i] == '\"' || cmd[i] == '\''))
		count = ft_qoutes(cmd, &i, init);
	else
		count = ft_word(cmd, &i, init);
	ft_add_to_list_tokens(list, ft_init_token(cmd, init, count, env));
	return (i);
}

t_token	*divide(char *cmd, t_env *env)
{
	t_token	*lst;
	int		i;

	lst = NULL;
	i = 0;
	while (cmd[i] && cmd[i] == 32)
		i++;
	while (cmd[i])
	{
		if (cmd[i] == '|')
			i = ft_count_alloc(cmd, i, &lst, env);
		else if (cmd[i] == ' ')
			i = ft_count_alloc(cmd, i, &lst, env);
		else if (cmd[i] == '>')
			i = ft_count_alloc(cmd, i, &lst, env);
		else if (cmd[i] == '<')
			i = ft_count_alloc(cmd, i, &lst, env);
		else
			i = ft_count_alloc(cmd, i, &lst, env);
	}
	return (lst);
}

char	*ft_get_key_from_var(t_token *tok)
{
	char	*key;
	int		i;
	int		s;
	int		e;
	t_token *cur;

	cur = tok;
	i = 0;
	s = 0;
	e = 0;
	while (cur)
	{
		while (cur->content[i] && cur->content[i] != '$')
			i++;
		i = i + 1;
		s = i;
		while (cur->content[i] != '$' && cur->content[i])
			i++;
		e = i - 1;
		cur = cur->next;
	}
	i = 0;
		puts("out\n");
	key = malloc(sizeof(char) * ((e - s) + 1));
	while (s <= e)
	{
		printf("s %d\n",s);
		printf("e %d\n",e);
		puts("inside\n");
		printf("i %d\n",i);
		key[i] = cur->content[s];
		i++;
		s++;
	}
	key[i] = '\0';
	// strncpy(key,cur->content,e - s);
	// printf("%s\n",strncpy(key, cur->content, e - s));
	return (key);
}

// void	ft_expand(char *cmd, t_env *env, t_token *tok)
// {
	// int 	i;
	// t_env	*tmp;
// 
	// tmp = env;
	// i = 0;
	// while (cmd[i])
	// {
// 
	// }
	// 
	// while (tmp)
	// {
		// 
		// tmp = tmp->next;
	// }
	// 
// }
