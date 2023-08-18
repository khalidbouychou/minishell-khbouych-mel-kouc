/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:58:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/18 15:32:13 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*ft_h_h_expand(char *cnt, t_exp *v)
{
	char	*r;
	char	*sub;
	char	*join;

	r = ft_strdup("");
	join = r;
	if (cnt[++v->i] != '$')
	{
		v->s = v->i;
		while (cnt[v->i] != '$')
			v->i++;
		v->e = v->i;
		sub = ft_substr(cnt, v->s, (v->e - v->s));
		r = ft_strjoin(join, sub);
		free(sub);
		free(join);
	}
	if (cnt[v->i] == '\'')
		r = expand_sq(cnt, v, r, join);
	return (r);
}

void	not_isalnum(char *cnt, t_exp *v)
{
	char	*sub;
	char	*tmp1;

	v->s = v->i;
	while (cnt[v->i] != '$' && cnt[v->i]
		&& !ft_isalnum(cnt[v->i]) && cnt[v->i] != '\'')
		v->i++;
	v->e = v->i;
	sub = ft_substr(cnt, v->s, (v->e - v->s));
	tmp1 = v->r;
	v->r = ft_strjoin(v->r, sub);
	free (tmp1);
	free(sub);
}

void	expand_digit(char *cnt, t_exp *v)
{
	char	*sub;
	char	*tmp1;

	++v->i;
	v->s = v->i;
	while (cnt[v->i] && cnt[v->i] != '$'
		&& ft_isdigit(cnt[v->i]) && cnt[v->i] != '\'')
		v->i++;
	v->e = v->i;
	sub = ft_substr(cnt, v->s, (v->e - v->s));
	tmp1 = v->r;
	v->r = ft_strjoin(tmp1, sub);
	free (tmp1);
	free(sub);
}

void	substr_expand(char *cnt, t_exp *v, t_env *env)
{
	char	*sub;
	char	*tmp;
	char	*tmp1;

	if (ft_isdigit(cnt[v->i]))
		expand_digit(cnt, v);
	else
	{
		v->s = v->i;
		while (cnt[v->i] && cnt[v->i] != '$'
			&& ft_isalnum(cnt[v->i]) && cnt[v->i] != '\'')
			v->i++;
		v->e = v->i;
		sub = ft_substr(cnt, v->s, (v->e - v->s));
		tmp = ft_v_k(sub, env);
		if (tmp)
		{
			tmp1 = v->r;
			v->r = ft_strjoin(tmp1, tmp);
			free (tmp1);
			free (tmp);
		}
		free(sub);
	}
	not_isalnum(cnt, v);
}

char	*ft_expandhelp(char *cnt, t_env *env)
{
	t_exp	v;
	// (void)env;
	ft_init_var_expd(&v);
	v.r = ft_h_h_expand(cnt, &v);
	while (cnt[++v.i])
		substr_expand(cnt, &v, env);
	return (v.r);
}
