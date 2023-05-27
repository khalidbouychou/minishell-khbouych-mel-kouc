/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:19:46 by khbouych          #+#    #+#             */
/*   Updated: 2022/10/13 20:26:18 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	x;

	x = (long int)nb;
	if (x < 0)
	{
		x *= -1;
		ft_putchar_fd('-', fd);
	}
	if (x >= 10)
		ft_putnbr_fd(x / 10, fd);
	ft_putchar_fd((x % 10) + 48, fd);
}
