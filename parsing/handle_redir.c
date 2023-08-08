/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:20:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/07 11:46:51 by khbouych         ###   ########.fr       */
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
	char		*count;
	int static	i;

	i++;
	str = "herdoc";
	count = ft_itoa(i);
	str = ft_strjoin(str, count);
	free(count);
	return (str);
}

t_token	*output_append_function(t_token *tmp, t_parse *new_p)
{
	if (tmp->type == OUTPUT)
	{
		if (new_p->fd_output != 1)
			close(new_p->fd_output);
		while (tmp && tmp->type != FIL)
			tmp = tmp->next;
		new_p->f_name = tmp->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT
				| O_RDWR | O_TRUNC, 0666);
	}
	else
	{
		if (new_p->fd_output != 1)
			close(new_p->fd_output);
		new_p->f_name = tmp->next->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT
				| O_RDONLY | O_WRONLY | O_APPEND, 0666);
	}
	return (tmp);
}

t_token	*ft_handle_oper(t_token *tmp, t_parse *new_p, int *flag)
{
	if (*(tmp->next)->content == '\0')
	{
		*flag = 1;
		ft_putstr_fd("ambiguous redirect\n", 2);
		return (tmp);
	}
	if (tmp->type == INPUT)
	{
		if (new_p->fd_input != 0)
			close(new_p->fd_input);
		new_p->f_name = tmp->next->content;
		new_p->fd_input = open(new_p->f_name, O_RDONLY, 0666);
	}
	else if (tmp->type == OUTPUT || tmp->type == APPND)
		tmp = output_append_function(tmp, new_p);
	if (new_p->fd_input == -1 || new_p->fd_output == -1)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		*flag = 1;
	}
	return (tmp);
}
