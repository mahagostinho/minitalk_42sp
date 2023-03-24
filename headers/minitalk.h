/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:13:09 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/24 20:04:30 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include "../libs/libft/headers/libft.h"

void	error_message(char *message);
int		process_id_is_digit(char *str_pid);
void	check_input(int argc, char **argv);
void	check_message_received(int signal);
void	send_message(pid_t pid, char *message);
void	print_message(int signal, siginfo_t *info, void *ucontext);
void	send_signal(pid_t pid, int signal);

#endif
