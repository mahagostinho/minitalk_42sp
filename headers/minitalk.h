/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:13:09 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/24 12:14:30 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include "../libs/libft/headers/libft.h"

/* Client_utils */
void	error_message(char *message);
int		process_id_is_digit(char *str_pid);
void	check_input(int argc, char **argv);

#endif
