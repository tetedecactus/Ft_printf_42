/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:58:56 by olabrecq          #+#    #+#             */
/*   Updated: 2021/07/23 10:48:32 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_conversion(char *format, t_count *count)
{
	if (format[count->index] == 'c')
		count->nb_bytes += ft_putchar(va_arg(count->argument, int));
	else if (format[count->index] == 's')
		count->nb_bytes += ft_putstr(va_arg(count->argument, char *));
	else if (format[count->index] == 'd' || format[count->index] == 'i')
		count->nb_bytes += ft_putnbr(va_arg(count->argument, int));
	else if (format[count->index] == 'u')
		count->nb_bytes += ft_putnbr(va_arg(count->argument, unsigned int));
	else if (format[count->index] == 'x' || format[count->index] == 'X')
		count->nb_bytes += print_hexa(va_arg(count->argument, unsigned int),
				format[count->index]);
	else if (format[count->index] == 'p')
		count->nb_bytes += print_pointer_hexa(va_arg(count->argument, void *),
				format[count->index]);
	else if (format[count->index] == '%')
		count->nb_bytes += ft_putchar('%');
}
