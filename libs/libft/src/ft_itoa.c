/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:43:22 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:07:39 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	absolute(int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

static	void	convert(char *num, int n, size_t size)
{
	num[size] = '\0';
	size--;
	if (n >= 0)
	{
		while (size)
		{
			num[size] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
		num[size] = n + '0';
	}
	else
	{
		while (size)
		{
			num[size] = absolute(n % 10) + '0';
			n = n / 10;
			size--;
		}
		num[size] = '-';
	}
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*num;
	int		aux;

	if (n >= 0)
		size = 1;
	else
		size = 2;
	aux = n / 10;
	while (aux)
	{
		size++;
		aux = aux / 10;
	}
	num = (char *)malloc(size + 1);
	if (num == NULL)
		return (NULL);
	else
		convert(num, n, size);
	return (num);
}
