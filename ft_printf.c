/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:32:56 by olabrecq          #+#    #+#             */
/*   Updated: 2021/07/26 10:30:10 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_count	init_struct(void)
{
	t_count	count;

	count.index = 0;
	count.nb_bytes = 0;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_count	count;

	count = init_struct();
	va_start(count.argument, (char *)format);
	while (format[count.index])
	{
		print_till_sign((char *)format, &count);
		count.index++;
	}
	return (count.nb_bytes);
}
