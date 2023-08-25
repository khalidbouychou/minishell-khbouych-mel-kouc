/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:05:12 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/25 14:06:13 by khbouych         ###   ########.fr       */
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

void	sub_expand_value(char *cnt, t_exp *v, t_env *env, int *echo_flag)
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
	if (*echo_flag == 1)
	{
		tmp = ft_trim_spaces_echo(tmp);
	}
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

void	check_cmd(t_token **lst)
{
	t_token	*tmp;
	t_token	*ptr;
	t_token	*space;
	int		_flag;

	_flag = 0;
	space = NULL;
	tmp = *lst;
	while (tmp)
	{
		ptr = tmp->next;
		if (ptr)
			ptr = check_echo(tmp, ptr, space, &_flag);
		if (!ptr)
			break ;
		tmp = ptr->next;
	}
}
