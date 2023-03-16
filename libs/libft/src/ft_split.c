/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:41:22 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:10:09 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		if (*(s + i) != '\0')
			counter++;
		while (*(s + i) != c && *(s + i))
			i++;
	}
	return (counter);
}

static int	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len ++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		counter;
	int		i;
	int		len;

	i = 0;
	counter = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (counter + 1));
	if (result == NULL)
		return (NULL);
	while (*s && i < counter)
	{
		while (*s == c && *s)
			s++;
		if (*s != c)
		{
			len = ft_word_len(s, c);
			*(result + i) = ft_substr(s, 0, len);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	*(result + counter) = NULL;
	return (result);
}
