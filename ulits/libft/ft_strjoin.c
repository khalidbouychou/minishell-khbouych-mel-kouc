/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:19 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/27 18:05:29 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res_joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res_joined == NULL)
		return (NULL);
	else
		while (s1[i])
			res_joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res_joined[j++] = s2[i++];
	res_joined[j] = '\0';
	return (res_joined);
}
