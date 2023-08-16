/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:34:45 by mel-kouc          #+#    #+#             */
/*   Updated: 2023/08/16 18:12:44 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}


void her_handler(int sig)
{
	(void)sig;
	if (g_stu.sig)
    {
        ft_putstr_fd("\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        g_stu.ex_stu = 1;
    }
}

int	write_in_herdoc(t_token *ptr, t_parse *new_p, t_env *env)
{
	char	*str;
	char	*delim;
	char	*buffer;
	// int		pid;

	delim = ptr->content;
	buffer = NULL;
	new_p->f_name = generate_name();
	unlink("/tmp/herdoc");
	int fd = open("/tmp/herdoc", O_WRONLY | O_CREAT, 0644);
	// pid = fork();
	// if (pid == 0)
	// {
		// signal(SIGQUIT, SIG_DFL);

		// signal(SIGINT, SIG_DFL);
		// while (!g_stu.sig)
		puts("");
		while (1)
		{
			str = readline("> ");
			if (!str && g_stu.sig == 0)
				return (unlink("/tmp/herdoc"),-1);
			if (!str || !ft_strncmp(delim, str, ft_strlen(str)))
			{
				// new_p->fd_input = open(new_p->f_name, O_WRONLY | O_CREAT, 0644);
				// if (buffer)
				// 	write(new_p->fd_input, buffer, ft_strlen(buffer));
				write(fd, buffer, ft_strlen(buffer));
				new_p->fd_input = open("/tmp/herdoc", O_RDONLY, 0644);
				break ;
			}
			if (ft_strchr(str, '$') != -1 && ptr->flag != 1)
				str = ft_expandhelp(str, env);
			buffer = ft_strjoin(buffer, str);
			buffer = ft_strjoin(buffer, "\n");
		}
		// unlink("/tmp/herdoc");
		close(fd);
		// unlink(new_p->f_name);
		// g_stu.ex_stu = 0;
	// }
	// else
	// 	kill(pid, SIGINT);
	// waitpid(pid, &status, 0);
	// if (WIFEXITED(status))
	// {
	// 	g_stu.ex_stu = WEXITSTATUS(status);
	// 	printf("status %d\n", g_stu.ex_stu);
	// 	new_p->fd_input = open(new_p->f_name, O_RDONLY, 0644);
	// }
	// else if (WIFSIGNALED(status))
	// 	if (WTERMSIG(status) == SIGQUIT)
	// 		ft_putendl_fd("Quit: 3", 2);
	return (0);
}


int	 ft_herdoc(t_token *tmp, t_parse *new_p, t_env *env)
{
	t_token	*ptr;

	g_stu.sig = 0;
	if (!tmp->prev)
		g_stu.flag = 1;
	ptr = tmp->next;
	if (new_p->fd_input > 2)
		close(new_p->fd_input);
	if (write_in_herdoc(ptr, new_p, env) == -1)
		return (-1);
	return (0);
}
