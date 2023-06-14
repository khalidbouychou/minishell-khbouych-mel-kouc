/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:40:34 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/06/13 13:20:16 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	while (*str1 && *str1 == *str2 && n)
	{
		str1++;
		str2++;
		n--;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;

// 	if (s1 == NULL || set == NULL)
// 		return (NULL);
// 	while (*s1 && ft_strchr(*s1, set))
// 		s1++;
// 	i = ft_strlen(s1);
// 	while (i && ft_strchr(*(s1 + i),set))
// 		i--;
// 	return (ft_substr(s1, 0, i + 1));
// }
