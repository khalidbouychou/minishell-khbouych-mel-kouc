/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:44:30 by khbouych          #+#    #+#             */
/*   Updated: 2023/07/22 13:50:10 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incld/minishell.h"

int	ft_is_key_exist(char *key, char **tkeys)
{
	int	i;

	i = 0;
	while (tkeys[i])
	{
		if (ft_strcmp(tkeys[i], key) != 0)
			return (0);
		i++;
	}
	return (1);
}
