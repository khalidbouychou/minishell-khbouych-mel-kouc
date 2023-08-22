/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:05:12 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/22 19:14:51 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

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
