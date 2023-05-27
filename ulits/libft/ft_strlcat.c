/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:44:06 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/26 09:31:03 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = -1;
	lensrc = ft_strlen(src);
	if (!size)
		return (lensrc);
	lendst = ft_strlen(dst);
	if (lendst > size)
		lensrc += size;
	else
		lensrc += lendst;
	while (src[++i] != '\0' && lendst < size - 1)
		dst[lendst++] = src[i];
	dst[lendst] = '\0';
	return (lensrc);
}
