/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:29:22 by olabrecq          #+#    #+#             */
/*   Updated: 2021/07/26 10:30:49 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	nb_bytes;

	return (nb_bytes = write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	nb_bytes;

	if (!str)
		nb_bytes = write(1, "(null)", 6);
	else
		nb_bytes = write(1, &*str, ft_strlen(str));
	return (nb_bytes);
}

int	ft_putnbr(long nb)
{
	static int	nb_bytes;
	int			nb_bytes_minus;

	nb_bytes_minus = 0;
	nb_bytes = 0;
	if (nb < 0)
	{
		nb_bytes_minus = ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb /10);
		nb %= 10;
	}
	nb_bytes += ft_putchar(nb + '0');
	return (nb_bytes + nb_bytes_minus);
}
