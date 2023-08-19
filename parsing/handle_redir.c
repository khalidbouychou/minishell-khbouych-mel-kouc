/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:20:43 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/19 19:49:04 by mel-kouc         ###   ########.fr       */
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
				| O_RDWR | O_TRUNC, 0644);
	}
	else
	{
		if (new_p->fd_output != 1)
			close(new_p->fd_output);
		new_p->f_name = tmp->next->content;
		new_p->fd_output = open(new_p->f_name, O_CREAT
				| O_RDWR | O_APPEND, 0644);
	}
	return (tmp);
}

int	type_er_env(t_token *tmp)
{
	struct stat	file_stat;

	if (stat(tmp->content, &file_stat) == 0)
	{
		if (S_ISDIR(file_stat.st_mode))
		{
			ft_putstr_fd("is a directory\n", 2);
			return (0);
		}
	}
	else if (ft_strchr(tmp->content, 32) != -1)
	{
		ft_putstr_fd("ambiguous redirect\n", 2);
		g_v.ex_stu = 1;
		return (0);
	}
	return (1);
}

t_token	*aplay_redire(t_token *tmp, t_parse *new_p)
{
	if (!tmp->prev && !tmp->next->next)
		g_v.flag = 1;
	if (tmp->type == INPUT)
	{
		if (new_p->fd_input != 0)
			close(new_p->fd_input);
		new_p->f_name = tmp->next->content;
		new_p->fd_input = open(new_p->f_name, O_RDONLY, 0644);
	}
	else if (tmp->type == OUTPUT || tmp->type == APPND)
		tmp = output_append_function(tmp, new_p);
	return (tmp);
}

t_token	*ft_handle_oper(t_token *tmp, t_parse *new_p, int *flag)
{
	if ((!tmp->prev && !type_er_env(tmp->next)) || !type_er_env(tmp->next))
	{
		*flag = 1;
		g_v.flag = 1;
	}
	else
	{
		if (*(tmp->next)->content == '\0')
		{
			*flag = 1;
			ft_putstr_fd("ambiguous redirect\n", 2);
			g_v.ex_stu = 1;
			return (tmp);
		}
		tmp = aplay_redire(tmp, new_p);
		// if (!tmp->prev && !tmp->next->next)
		// 	g_v.flag = 1;
		// if (tmp->type == INPUT)
		// {
		// 	if (new_p->fd_input != 0)
		// 		close(new_p->fd_input);
		// 	new_p->f_name = tmp->next->content;
		// 	new_p->fd_input = open(new_p->f_name, O_RDONLY, 0644);
		// }
		// else if (tmp->type == OUTPUT || tmp->type == APPND)
		// 	tmp = output_append_function(tmp, new_p);
		if (new_p->fd_input == -1 || new_p->fd_output == -1)
		{
			ft_putstr_fd("No such file or directory\n", 2);
			*flag = 1;
			g_v.flag = 1;
		}
	}
	return (tmp);
}
