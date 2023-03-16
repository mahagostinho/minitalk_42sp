/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:40:57 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:11:25 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	initial_pos(char const *s1, char const *set)
{
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	while (j < ft_strlen(set))
	{
		if (*s1 == set[j])
		{
			i++;
			s1++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	final_pos(char const *s1, char const *set)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (s1[k] && j < ft_strlen(set))
	{
		if (s1[k] == set[j])
		{
			i++;
			k--;
			j = 0;
		}
		else
			j++;
	}
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		final;

	start = initial_pos(s1, set);
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	final = final_pos(s1, set);
	result = ft_substr(s1, start, final - start);
	return (result);
}
