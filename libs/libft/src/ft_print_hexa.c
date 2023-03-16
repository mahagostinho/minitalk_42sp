/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:16:16 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:04:19 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_print_hexa(unsigned int nbr, char letter)
{
	int		printed;
	char	*digits;

	printed = 0;
	if (letter == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (nbr < 16)
		printed += ft_print_char(digits[nbr]);
	else
	{
		printed += ft_print_hexa(nbr / 16, letter);
		printed += ft_print_hexa(nbr % 16, letter);
	}
	return (printed);
}

int	ft_print_hexa_long(unsigned long long hexa)
{
	int		printed;
	char	*digits;

	printed = 0;
	digits = "0123456789abcdef";
	if (hexa < 16)
		printed += ft_print_char(digits[hexa]);
	else
	{
		printed += ft_print_hexa_long(hexa / 16);
		printed += ft_print_hexa_long(hexa % 16);
	}
	return (printed);
}
