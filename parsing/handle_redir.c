/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:20:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/07/25 14:40:43 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

char	*tr_str(int len, char *str, int n)
{
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		str[0] = 0;
		return (str);
	}
	while (n)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;
	int		n;

	n = nbr;
	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = tr_str(len, str, n);
	return (str);
}

char	*generate_name(void)
{
	char		*str;
	int static	i;

	i++;
	str = "herdoc";
	str = ft_strjoin(str, ft_itoa(i));
	return (str);
}

t_token	*ft_handle_oper(t_token *tmp, t_parse *new_p)
{
	// 4 : READ
	// 2 : write
	// 1 : execute
	// perror, strerror
	if (tmp->type == INPUT)
	{
		if (new_p->fd_input != -4)
			close(new_p->fd_input);
		new_p->f_name = tmp->next->content;
		new_p->fd_input = open(new_p->f_name, O_RDONLY, 0666);
		if (new_p->fd_input == -1)
			ft_putstr_fd("No such file or directory\n", 2);
	}
	else if (tmp->type == OUTPUT)
	{
		if (new_p->fd_output != -5)
			close(new_p->fd_output);
		new_p->f_name = tmp->next->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT | O_RDONLY | O_TRUNC, 0666);
		if (new_p->fd_output == -1)
			ft_putstr_fd("unexpected error\n", 2);
	}	
	else
	{
		if (new_p->fd_output != -5)
			close(new_p->fd_output);
		new_p->f_name = tmp->next->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT | O_RDONLY | O_APPEND, 0666);
		if (new_p->fd_output == -1)
			ft_putstr_fd("unexpected error\n", 2);
	}
	return (tmp->next);
}

