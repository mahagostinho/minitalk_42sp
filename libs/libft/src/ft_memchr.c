/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:35 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:09:14 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*p;
	unsigned char	chr;

	chr = (unsigned char)c;
	p = (unsigned char *)s;
	i = 0;
	if (!s || !n)
		return (NULL);
	while (i <= n - 1)
	{
		if (*(p + i) == chr)
			return ((void *)p + i);
		i++;
	}
	return (NULL);
}
