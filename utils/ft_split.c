/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:01:48 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 20:27:54 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

static size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	nbr_words;

	i = 0;
	nbr_words = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			nbr_words++;
		i++;
	}
	return (nbr_words);
}

static size_t	ft_len_word(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_clear_leak(char **output, int nbr_words)
{
	int	i;

	i = -1;
	while (++i < nbr_words)
		free(output[i]);
	free(output);
	return (0);
}

static char	**ft_form_words(char const *str, char c, int nbr_words,
		char **output)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < nbr_words)
	{
		while (*str == c)
			str++;
		len = ft_len_word(str, c);
		output[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!output[i])
			return (ft_clear_leak(output, i));
		j = 0;
		while (j < len)
			output[i][j++] = *str++;
		output[i][j] = '\0';
	}
	output[i] = NULL;
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
	output = ft_form_words(s, c, ft_count_words(s, c), output);
	return (output);
}
