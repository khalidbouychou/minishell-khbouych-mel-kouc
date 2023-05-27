/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:00:32 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/26 17:40:48 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(s1);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, s1, size);
	tmp[size] = '\0';
	return (tmp);
}
