/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:52:18 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/23 14:27:39 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		string[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
