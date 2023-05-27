/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:04:47 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/27 14:08:15 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	long long	nbr;

	nbr = n;
	len = ft_nbrlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	while (nbr > 0)
	{
		res[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	return (res);
}
