/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:51:30 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/25 16:02:43 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

static	int	ft_power(long n)
{
	int	power;

	power = 0;
	if (n <= 0)
	{
		n = -n;
		power++;
	}
	while (n > 0)
	{
		n = n / 10;
		power++;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	int		power;
	char	*str;
	long	nb;

	nb = n;
	power = ft_power(nb);
	str = (char *)malloc(sizeof (char) * (power + 1));
	if (!str)
		return (0);
	str[power] = '\0';
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[power - 1] = nb % 10 + 48;
		nb = nb / 10;
		power--;
	}
	return (str);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 && *str1 == *str2 && n)
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	ft_check_by_key(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_find_shellvl(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], "SHLVL", 4))
			return (i);
		i++;
	}
	return (-1);
}
