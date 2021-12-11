/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:32:56 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/24 10:44:37 by olabrecq         ###   ########.fr       */
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

int main()
{
	int num = 19;
	int nb_bytes;
	int real_nb_bytes;
	
	nb_bytes = ft_printf("%c\n", 'd');
	real_nb_bytes = printf("%c\n", 'd');
	printf("nb_bytes = %q\n", nb_bytes);
	printf("real _nb = %d\n", real_nb_bytes);
	// ft_printf("%p\n", num);
	// ft_printf("%u\n", num);
	// ft_printf("%x\n", num);
	// ft_printf("%X\n", num);
	// ft_printf("%c\n", num);
	// ft_printf("%s\n", num);

	
}