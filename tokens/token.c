/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:10:14 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/01 18:24:37 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"
// int ft_check_if_cmd_valid(char **path,char *cmd)
// {
	// 
// }
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
		count = ft_Qoutes(cmd, &i, init);
	else
		count = ft_Word(cmd, &i, init);
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
			i = ft_count_alloc(cmd, i, &lst,env);
		else if (cmd[i] == ' ')
			i = ft_count_alloc(cmd, i, &lst,env);
		else if (cmd[i] == '>')
			i = ft_count_alloc(cmd, i, &lst,env);
		else if (cmd[i] == '<')
			i = ft_count_alloc(cmd, i, &lst,env);
		else
			i = ft_count_alloc(cmd, i, &lst,env);
	}
	return (lst);
}
