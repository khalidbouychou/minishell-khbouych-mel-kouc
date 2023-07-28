/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:45:22 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/28 10:20:51 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

static void	ft_skipp(int *i, const char *p_str, int *sign)
{
	while ((p_str[*i] >= 9 && p_str[*i] <= 13) || p_str[*i] == ' ')
		(*i)++;
	if (p_str[*i] == '-' || p_str[*i] == '+')
	{
		if (p_str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

long long	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;
	char		*p_str;
	long long	prev_res;

	p_str = (char *)str;
	i = 0;
	res = 0;
	sign = 1;
	ft_skipp(&i, &str[i], &sign);
	while (ft_isdigit(p_str[i]))
	{
		prev_res = res;
		res = res * 10 + p_str[i] - '0';
		if ((res / 10) != prev_res)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (sign * res);
}       

int	ft_check_arg_is_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	return (1);
}

int	ft_check_overflow(char *arg)
{
	if (ft_atoi(arg) > ft_atoi("9223372036854775807")
		|| ft_atoi(arg) < ft_atoi("-9223372036854775808"))
	{
		g_stu.ex_stu = 255;
		return (0);
	}
	else
		g_stu.ex_stu = ft_atoi(arg);
	return (1) ;
}
