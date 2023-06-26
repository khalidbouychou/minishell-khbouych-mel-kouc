/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:12:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/06/25 17:04:38 by mel-kouc         ###   ########.fr       */
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

char	*ft_expandhelp(char *cnt, t_env *env)
{
	t_exp	v;

	ft_init_var_expd(&v);
	if (cnt[++v.i] != '$')
	{
		v.s = v.i;
		while (cnt[v.i] != '$')
			v.i++;
		v.e = v.i;
		v.r = ft_strjoin(v.r, ft_substr(cnt, v.s, (v.e - v.s)));
	}
	while (cnt[++v.i])
	{
		v.s = v.i;
		while (cnt[v.i] != '$' && cnt[v.i] && ft_isalnum(cnt[v.i]))
			v.i++;
		v.e = v.i;
		v.r = ft_strjoin(v.r, ft_v_k(ft_substr(cnt, v.s, (v.e - v.s)), env));
		v.s = v.i;
		while (cnt[v.i] != '$' && cnt[v.i] && !ft_isalnum(cnt[v.i]))
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

	res = NULL;
	tmp = tok;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '$') != -1)
			res = ft_strjoin(res, ft_expandhelp(tmp->content, env));
		tmp = tmp->next;
	}
	printf("res_expander = %s\n", res);
}
