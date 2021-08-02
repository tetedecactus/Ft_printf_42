/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_till_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:17:13 by olabrecq          #+#    #+#             */
/*   Updated: 2021/07/23 10:49:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_till_sign(char *format, t_count *count)
{
	if (format[count->index] != '%')
	{
		count->nb_bytes += ft_putchar(format[count->index]);
	}
	else if (format[count->index] == '%')
	{
		count->index++;
		check_conversion(format, count);
	}
}
