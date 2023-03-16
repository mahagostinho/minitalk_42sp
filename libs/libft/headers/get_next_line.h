/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:24 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/04 21:46:23 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft.h"
# include <limits.h>

# define BUFFER_SIZE 10
# define READ_OK 1
# define MALLOC_ERROR -1
# define MALLOC_ERROR2 -2
# define INPUT_ERROR -1
# define NO_LINE_FEED -1
# define OPEN_MAX 256

int		get_next_line(int fd, char **line);
void	gnl_next(char **next, char *aux, int only_next);
int		gnl_split(char *str, char **next, char *tmp, int only_next);
int		check_new_line(char *str, char **next, char *tmp, int only_next);
int		gnl_read(int fd, char *buf, char **next, char *tmp);
void	gnl_strjoin(char **next, char *buffer);
void	ft_clean(char **str);

#endif
