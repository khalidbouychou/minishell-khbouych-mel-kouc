/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:00:38 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/26 15:20:45 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	tsize;

	tsize = count * size;
	if (count != 0 && size != tsize / count)
		return (0);
	tmp = (char *)malloc(tsize);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, tsize);
	return (tmp);
}
