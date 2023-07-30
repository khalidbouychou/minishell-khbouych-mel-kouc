/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:17:41 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/27 10:03:04 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_help_join(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strdup("");
	if (*(s1) == NULL)
	{
		*(s1) = tmp;
		*(s1)[0] = '\0';
	}
	if (*(s2) == NULL)
	{
		*(s2) = tmp;
		*(s2)[0] = '\0';
	}
	free (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res_joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_help_join(&s1, &s2);
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

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
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
