/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:34:43 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/24 18:33:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src == NULL && dest == NULL)
		return (dest);
	if (dest < src)
		while (++i < len)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	else
		while (len-- > 0)
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	return (dest);
}
