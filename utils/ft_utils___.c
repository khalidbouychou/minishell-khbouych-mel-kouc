/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils___.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:25:05 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/21 21:44:32 by mel-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	add_if_not_found(t_env **head, int i)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	while (++i < 4)
	{
		env_not_exist(i, &key, &value);
		ft_lst_addback(head, add_env(key, value));
	}
}

t_env	*env_list(char **env)
{
	int		i;
	t_env	*head;
	t_env	*old;

	(void)env;
	head = NULL;
	i = -1;
	head = NULL;
	g_v.current_pwd = getcwd(NULL, 0);
	if (*env == NULL)
		add_if_not_found(&head, i);
	else
	{
		i = 0;
		while (env[i])
		{
			ft_lst_addback(&head, ft_lstnew(env[i]));
			i++;
		}
	}
	old = ft_getenv_node(head, "OLDPWD");
	if (!old)
		ft_lst_addback(&head, ft_add_env(ft_strdup("OLDPWD"), NULL));
	return (head);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
