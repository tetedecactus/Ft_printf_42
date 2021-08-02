/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_outils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 09:16:44 by olabrecq          #+#    #+#             */
/*   Updated: 2021/07/23 11:02:24 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long long nbr, char format)
{
	int	nb_bytes;

	nb_bytes = 0;
	if (nbr >= 16)
	{
		nb_bytes += print_hexa(nbr / 16, format);
		nb_bytes += print_hexa(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			nb_bytes += ft_putchar(nbr + '0');
		else
		{
			if (format == 'x')
				nb_bytes += ft_putchar(nbr - 10 + 'a');
			else if (format == 'X')
				nb_bytes += ft_putchar(nbr - 10 + 'A');
		}
	}
	return (nb_bytes);
}

int	print_pointer_hexa(void *nbr, char format)
{
	void			*ptr;
	int				nb_bytes;
	unsigned long	num;

	ptr = nbr;
	num = (unsigned long) ptr;
	format = 'x';
	nb_bytes = 0;
	nb_bytes += ft_putstr("0x");
	return (nb_bytes += print_hexa(num, 'x'));
}
