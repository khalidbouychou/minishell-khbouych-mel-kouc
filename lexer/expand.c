/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:12:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/24 18:33:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_init_var_expd(t_exp *var_expd, int *dollar)
{
	var_expd->i = -1;
	var_expd->s = 0;
	var_expd->e = 0;
	var_expd->r = NULL;
	*dollar = 0;
}

char	*expand_sq(char *cnt, t_exp *v, char *r, char *join)
{
	char	*sub;

	v->i++;
	v->s = v->i;
	while (cnt[v->i] != '\'')
		v->i++;
	v->e = v->i;
	sub = ft_substr(cnt, v->s, (v->e - v->s));
	r = ft_strjoin(r, sub);
	free(sub);
	free(join);
	return (r);
}

char	*ft_v_k(char *key, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(key, env->key) == 0)
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

void	expand_redir(t_token *tmp, t_env *env)
{
	t_token	*dolar;
	t_token	*ptr;
	char	*tmp1;

	if (tmp->type == VAR)
	{
		dolar = tmp;
		ptr = tmp->prev;
		while (ptr && (ptr->type == SPC || ptr->type == _TAB))
			ptr = ptr->prev;
		if ((ptr && (ptr->type != HERDOC))
			|| !ptr)
		{
			tmp1 = tmp->content;
			tmp->content = ft_expandhelp(tmp1, env);
			free (tmp1);
		}
		if (ptr && (ptr->type == OUTPUT || ptr->type == INPUT
				|| ptr->type == APPND)
			&& !ft_getenv_node(env, dolar->content))
			g_v._flag = 1;
	}
}

void	ft_expander(t_token *tok, t_env *env)
{
	t_token	*tmp;

	tmp = tok;
	while (tmp)
	{
		expand_redir(tmp, env);
		tmp = tmp->next;
	}
}
