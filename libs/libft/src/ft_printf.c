/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:56:14 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:03:22 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
	len += ft_printing((char *)format, args);
	va_end(args);
	return (len);
}

int	ft_printing(char *format, va_list args)
{
	int	i;
	int	len_str;

	i = 0;
	len_str = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len_str += ft_check_format(format, args, i);
		}
		else
			len_str += write(1, &format[i], 1);
		i++;
	}
	return (len_str);
}

int	ft_check_format(char *format, va_list args, int i)
{
	int	len_fmt;

	len_fmt = 0;
	if (format[i] == 'c')
		len_fmt = ft_print_char(va_arg(args, int));
	else if (format[i] == 's')
		len_fmt = ft_print_str(va_arg(args, char *));
	else if (format[i] == '%')
		len_fmt = ft_print_char('%');
	else if (format[i] == 'd' || format[i] == 'i')
		len_fmt = ft_print_nbr(va_arg(args, int));
	else if (format[i] == 'u')
		len_fmt = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		len_fmt = ft_print_hexa(va_arg(args, unsigned int), format[i]);
	else if (format[i] == 'p')
		len_fmt = ft_print_pointer(va_arg(args, void *));
	return (len_fmt);
}
