/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:12:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/01 21:32:06 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*ft_v_k(char *key, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(key, env->key, ft_strlen(env->key)) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	ft_init_var_expd(t_exp *var_expd)
{
	var_expd->i = -1;
	var_expd->s = 0;
	var_expd->e = 0;
	var_expd->r = NULL;
}

char	*ft_h_h_expand(char *cnt, int *i, int *s, int *e)
{
	char	*r;

	r = NULL;
	if (cnt[++*i] != '$')
	{
		*s = *(i);
		while (cnt[*i] != '$')
			(*i)++;
		*e = *(i);
		r = ft_strjoin(r, ft_substr(cnt, *s, (*e - *s)));
	}
	if (cnt[*i] == '\'')
	{
		i++;
		*s = *i;
		while (cnt[*i] != '\'')
			i++;
		*e = *i;
		r = ft_strjoin(r, ft_substr(cnt, *s, (*e - *s)));
	}
	return (r);
}

char	*ft_expandhelp(char *cnt, t_env *env)
{
	t_exp	v;

	ft_init_var_expd(&v);
	v.r = ft_h_h_expand(cnt, &v.i, &v.s, &v.e);
	while (cnt[++v.i])
	{
		v.s = v.i;
		while (cnt[v.i] != '$' && cnt[v.i]
			&& ft_isalnum(cnt[v.i]) && cnt[v.i] != '\'')
			v.i++;
		v.e = v.i;
		v.r = ft_strjoin(v.r, ft_v_k(ft_substr(cnt, v.s, (v.e - v.s)), env));
		v.s = v.i;
		while (cnt[v.i] != '$' && cnt[v.i]
			&& !ft_isalnum(cnt[v.i]) && cnt[v.i] != '\'')
			v.i++;
		v.e = v.i;
		v.r = ft_strjoin(v.r, ft_substr(cnt, v.s, (v.e - v.s)));
		v.s = v.i;
		while (cnt[v.i] != '$' && cnt[v.i])
			v.i++;
		v.e = v.i;
		v.r = ft_strjoin(v.r, ft_substr(cnt, v.s, (v.e - v.s)));
	}
	return (v.r);
}

void	ft_expander(t_token *tok, t_env *env)
{
	char			*res;
	t_token			*tmp;
	t_token			*ptr;

	res = NULL;
	res = NULL;
	tmp = tok;
	while (tmp)
	{
		if (tmp->type == VAR)
		{
			(void)env;
			ptr = tmp->prev;
			while (ptr && (ptr->type == SPACE || ptr->type == TAB))
				ptr = ptr->prev;
			if ((ptr && ptr->type != HERDOC) || !ptr)
			{
				res = ft_strjoin(res, ft_expandhelp(tmp->content, env));
				tmp->content = res;
			}
		}
		tmp = tmp->next;
	}
}
