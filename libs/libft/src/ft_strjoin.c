/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:08:37 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:10:30 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_new;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_new = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc((len_new + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		new[i] = (s1)[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		new[ft_strlen(s1) + i] = (s2)[i];
		i++;
	}
	new[len_new] = '\0';
	return (new);
}
