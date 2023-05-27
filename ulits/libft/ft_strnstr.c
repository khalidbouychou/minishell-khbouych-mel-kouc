/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:11 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/25 14:39:23 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!tofind[0])
		return ((char *)str);
	if (!str && len == 0)
		return (NULL);
	while (str[i] && i < len)
	{
		j = 0;
		if (tofind[j++] == str[i])
		{
			while (tofind[j] && tofind[j] == str[i + j])
				j++;
			if (!tofind[j] && (i + j) <= len)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
