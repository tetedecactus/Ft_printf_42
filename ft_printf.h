/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:58:09 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/09 08:45:29 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_count
{
	int		index;
	int		nb_bytes;
	va_list	argument;
}	t_count;

int		ft_printf(const char *format, ...);
int		ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long nb);
int		ft_putnbr_long(long nb);
int		print_hexa(unsigned long long nbr, char format);
int		print_pointer_hexa(void *nbr, char format);
void	check_conversion(char *format, t_count *count);
void	print_till_sign(char *format, t_count *count);

#endif
