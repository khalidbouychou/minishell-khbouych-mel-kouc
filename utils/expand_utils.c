/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:58:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/22 02:34:52 by khbouych         ###   ########.fr       */
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

void	join_after_exp(char *cnt, t_exp *v)
{
	char	*sub;
	char	*tmp1;

	v->s = v->i;
	while (cnt[v->i] != '$' && cnt[v->i])
		v->i++;
	v->e = v->i;
	sub = ft_substr(cnt, v->s, (v->e - v->s));
	tmp1 = v->r;
	v->r = ft_strjoin(tmp1, sub);
	free (tmp1);
	free(sub);
}

void	sub_expand_value(char *cnt, t_exp *v, t_env *env)
{
	char	*sub;
	char	*tmp;
	char	*tmp1;

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

char *fttest(char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	tmp = malloc(sizeof(char) * (len + 2));
	len = ft_strlen(str);
	tmp[0] = '0';
	while (str[i])
	{
		tmp[i + 1] = str[i];
		i++;
	}
	tmp[i + 1] = '\0';
	return (tmp);
}
char	*substr_expand(char *cnt, t_exp *v, t_env *env)
{
	char	*str;

	if (ft_isdigit(cnt[v->i]))
		expand_digit(cnt, v);
	else if (cnt[v->i] == '?')
	{
		str = ft_itoa(g_v.ex_stu);
		free(cnt);
		cnt = fttest(str);
		free(str);
	}
	else
		sub_expand_value(cnt, v, env);
	not_isalnum(cnt, v);
	join_after_exp(cnt, v);
	return (cnt);
}

char	*ft_expandhelp(char *cnt, t_env *env)
{
	t_exp	v;

	ft_init_var_expd(&v);
	v.r = ft_h_h_expand(cnt, &v);
	++v.i;
	while (v.i < (int)ft_strlen(cnt))
	{
		cnt = substr_expand(cnt, &v, env);
		v.i++;
	}
	return (v.r);
}
