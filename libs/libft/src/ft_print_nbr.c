/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:56:01 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:04:04 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_print_char('-');
		len += ft_print_char('2');
		len += ft_print_nbr(147483648);
	}
	else if (n < 0)
	{
		len += ft_print_char('-');
		len += ft_print_nbr(-1 * n);
	}
	else if (n >= 0 && n <= 9)
		len += ft_print_char((n + 48));
	else
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_char(((n % 10) + 48));
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 9)
		len += ft_print_char((n + 48));
	else
	{
		len += ft_print_unsigned(n / 10);
		len += ft_print_char(((n % 10) + 48));
	}
	return (len);
}
