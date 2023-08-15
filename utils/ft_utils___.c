/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils___.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:25:05 by khbouych          #+#    #+#             */
/*   Updated: 2023/08/15 14:48:46 by mel-kouc         ###   ########.fr       */
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
void	env_not_exist(int i, char **key, char **value)
{
	if (i == 0)
		{
			*key = ft_strdup("PWD");
			*value = ft_strdup(g_stu.current_pwd);
			g_stu.current_pwd = *value;
		}
		else if (i == 1)
		{
			*key = ft_strdup("SHLVL");
			*value = ft_strdup("1");
		}
		else if (i == 2)
		{
			*key = ft_strdup("_");
			*value = ft_strdup("/usr/bin/env");
		}
		else if (i == 3)
		{
			*key = ft_strdup("PATH");
			*value = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
		}
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
		// if (i == 0)
		// {
		// 	key = ft_strdup("PWD");
		// 	value = ft_strdup(g_stu.current_pwd);
		// 	g_stu.current_pwd = value;
		// }
		// else if (i == 1)
		// {
		// 	key = ft_strdup("SHLVL");
		// 	value = ft_strdup("1");
		// }
		// else if (i == 2)
		// {
		// 	key = ft_strdup("_");
		// 	value = ft_strdup("/usr/bin/env");
		// }
		// else if (i == 3)
		// {
		// 	key = ft_strdup("PATH");
		// 	value = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
		// }
		ft_lst_addback(head, add_env(key, value));
	}
}

t_env	*env_list(char **env)
{
	int		i;
	t_env	*head;
	t_env	*old;

	head = NULL;
	i = -1;
	head = NULL;
	g_stu.current_pwd = getcwd(NULL, 0);
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
		ft_lst_addback(&head, ft_add_env("OLDPWD", NULL));
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
