/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:23:59 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:09:20 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*fst;
	unsigned char	*sec;
	size_t			i;

	fst = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (fst[i] == sec[i] && n > i + 1 && fst)
		i++;
	return (fst[i] - sec[i]);
}
