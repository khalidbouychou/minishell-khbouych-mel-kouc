/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:09:11 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/24 16:17:04 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;
	size_t	i;

	if (dest == '\0' && src == '\0')
		return (0);
	p_dest = (char *)dest;
	p_src = (char *)src;
	i = -1;
	while (++i < n)
		p_dest[i] = p_src[i];
	return (p_dest);
}
