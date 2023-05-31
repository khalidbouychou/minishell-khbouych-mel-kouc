/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/30 21:52:00 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char *ft_get_relativepath(char *path , char *cmd)
{
	char **sp;
	sp = ft_split(path,':');
	path = ft_substr(sp[1],4,4);
	path = ft_strjoin(path,"/");
	path = ft_strjoin(path,cmd);
	return path;
}
char *ft_get_path(t_env *env ,char *cmd)
{
	char *path = NULL;
	t_env *tmp;
	tmp = env;
	while (tmp)
	{
		if(ft_strncmp(tmp->key,"PATH",4) == 0)
		{
			path = tmp->value;
			break;
		}
		tmp = tmp->next;
	}
	path = ft_get_relativepath(path,cmd);
	return path;
}
// static t_token *ft_init_token(char *cmd , t_env *env)
// {
// 	t_token *tok;
// 	tok = malloc(sizeof(t_token));
// 	tok->content = cmd;
// 	tok->type = WORD;
// 	tok->path = ft_get_path(env,cmd);
// 	tok->next = NULL;
// 	return tok;
// }

t_token	*ft_init_token(char *cmd, int i, int count)
{
	t_token	*tok;
	tok = malloc(sizeof(t_token));
	printf("i %d\n",i);
	printf("count %d\n",count);
	// while(i <= count)
	// {
		// printf("%c",cmd[i]);
		// i++;
	// }
	// puts("");
	tok->content = ft_substr(cmd,i,count);
	printf("%s\n",tok->content);
	tok->type = WORD;
	tok->path = NULL;
	tok->operator = 0;
	tok->next = NULL;
	return (tok);
}

void ft_add_to_list_tokens(t_token **lst_tok , t_token *newtok)
{
	t_token	*last;

	if (!lst_tok || !newtok)
		return ;
	else if (*lst_tok == 0)
		*lst_tok = newtok;
	else
	{
		last = ft_listlast(*lst_tok);
		last->next = newtok;
	}
}

int	ft_count_alloc(char *cmd, int i, t_token **list)
{
	int	count;
	int	init;
	count = 0;
	init = 0;
	if ((cmd [i] == '>' && cmd[i + 1] == '>') || (cmd [i] == '<' && cmd [i + 1] == '<'))
	{
		count = 2;
		
		ft_add_to_list_tokens(list, ft_init_token(cmd, i,(i + count) - 1));
		i = i + count;
	}
	else if (cmd [i] == '|' || cmd[i] == ' ' || cmd[i] == '>' || cmd[i] == '<')
	{
		count = 1;
		ft_add_to_list_tokens(list, ft_init_token(cmd, i,(i + count - 1)));
		i = i + count;
	}
	else
	{
		init = i;
		while (cmd[i] && (cmd [i] != '|' && cmd[i] != 32 && cmd[i] != '>' && cmd[i]!= '<'))
			i++;
		count = (i - init);
		ft_add_to_list_tokens(list, ft_init_token(cmd,init,init + count - 1));
	}
	return (i);
}

t_token	*divide(char *cmd)
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
			i = ft_count_alloc(cmd, i,&lst);
		else if (cmd[i] == ' ')
			i = ft_count_alloc(cmd, i,&lst);
		else if (cmd[i] == '>')
			i = ft_count_alloc(cmd, i,&lst);
		else if (cmd[i] == '<')
			i = ft_count_alloc(cmd, i,&lst);
		else
			i = ft_count_alloc(cmd, i,&lst);
	}
	return (lst);
}

// t_token *ft_new_token(char *cmd , t_env *env)
// {
//     t_token	*tok;
//     tok = ft_init_token(cmd,env);
//     if (!ft_strncmp("|", cmd, 255))
//     	tok->type = PIPE;
// 	else if (!ft_strncmp(">>", cmd, 255))
// 		tok->type = APPND;
// 	else if (!ft_strncmp(">", cmd, 255))
// 		tok->type = OUTPUT;
// 	else if (!ft_strncmp("<", cmd, 255))
// 		tok->type = INPUT;
// 	else if (!ft_strncmp("<<", cmd, 255))
// 		tok->type = HERDOC;
//     else if (!ft_strncmp("$", cmd, 255))
// 		tok->type = VAR;
//     if (tok->type != WORD)
//         tok->path = NULL;
//     if(tok->type != WORD && tok->type != VAR)
//         tok->operator = 1;
//     else
//         tok->operator = 0;
// 	return (tok);
// }

t_token	*ft_listlast(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

