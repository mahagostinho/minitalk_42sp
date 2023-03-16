/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:56:18 by marcarva          #+#    #+#             */
/*   Updated: 2022/10/31 16:34:20 by marcella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printing(char *format, va_list args);
int		ft_check_format(char *format, va_list args, int i);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_nbr(int n);
int		ft_count_size(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hexa(unsigned int nbr, char letter);
int		ft_print_pointer(void *ptr);
int		ft_print_hexa_long(unsigned long long hexa);

#endif
