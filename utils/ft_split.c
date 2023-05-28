/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:58:32 by khbouych          #+#    #+#             */
/*   Updated: 2023/05/28 21:11:32 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	nbr_words;

	i = 0;
	nbr_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbr_words++;
		i++;
	}
	return (nbr_words);
}

static int	ft_lenght_word(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_clear_leak(char **output, int count_w)
{
	int	i;

	i = -1;
	while (++i < count_w)
		free(output[i]);
	free(output);
	return (0);
}

static char	**ft_fill_words(char const *s, char c, int count_words,
		char **output)
{
	int	word;
	int	j;
	int	len;

	word = -1;
	while (++word < count_words)
	{
		while (*s == c)
			s++;
		len = ft_lenght_word(s, c);
		output[word] = (char *)malloc(sizeof(char) * (len + 1));
		if (!output[word])
			return (ft_clear_leak(output, word));
		j = -1;
		while (++j < len)
			output[word][j] = *s++;
		output[word][j] = '\0';
	}
	output[word] = "\0";
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;

	if (!s)
		return (0);
	output = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!output)
		return (0);
	output = ft_fill_words(s, c, ft_count_words(s, c), output);
	return (output);
}
