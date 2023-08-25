/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:58:03 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/25 15:57:19 by mel-kouc         ###   ########.fr       */
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

char	*fttest(char *str, char *cnt)
{
	size_t		i;
	int			len;
	int			len1;
	char		*tmp;

	i = 0;
	len = ft_strlen(str);
	len1 = ft_strlen(cnt) - 2;
	tmp = malloc(sizeof(char) * (len1 + len + 2));
	if (!tmp)
		return (NULL);
	tmp[0] = 31;
	while (i < ft_strlen(cnt))
		help_ft_test(tmp, cnt, &i, str);
	tmp[i + 1] = '\0';
	return (tmp);
}

char	*substr_expand(char *cnt, t_exp *v, t_env *env, int *echo_flag)
{
	char	*str;

	if (ft_isdigit(cnt[v->i]))
		expand_digit(cnt, v);
	else if (cnt[v->i] == '?')
	{
		str = ft_itoa(g_v.ex_stu);
		cnt = fttest(str, cnt);
		free(str);
	}
	else
		sub_expand_value(cnt, v, env, echo_flag);
	not_isalnum(cnt, v);
	join_after_exp(cnt, v);
	return (cnt);
}

char	*ft_norm_expand(char *cnt, t_exp v)
{
	if (ft_strcmp(cnt, "0") == 0)
	{
		v.r = ft_strdup("0");
		return (v.r);
	}
	return (NULL);
}

char	*ft_expandhelp(char *cnt, t_env *env, int *echo_flag)
{
	t_exp	v;
	int		dollar;

	ft_init_var_expd(&v, &dollar);
	v.r = ft_h_h_expand(cnt, &v);
	while (v.i < (int)ft_strlen(cnt))
	{
		if (cnt[v.i] == '$')
			dollar++;
		else
		{
			if (dollar % 2 != 0)
				cnt = substr_expand(cnt, &v, env, echo_flag);
			else
				return (return_v_r(cnt, &v));
		}
		v.i++;
	}
	if (ft_norm_expand(cnt, v) != NULL)
		return (ft_norm_expand(cnt, v));
	return (v.r);
}
