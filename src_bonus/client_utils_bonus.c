/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:35:48 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/27 12:36:00 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

int	g_answer;

void	error_message(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	check_message_received(int signal)
{
	if (signal == SIGUSR1)
		g_answer = 0;
	else if (signal == SIGUSR2)
		ft_printf("Message sent with success!\n");
}

void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal) != 0)
		error_message("Failed to send signal!");
}

void	send_message(pid_t pid, char *message)
{
	size_t	index;
	int		bits_counter;

	index = -1;
	while (++index <= ft_strlen(message))
	{
		bits_counter = 0;
		while (bits_counter < 8)
		{
			if (g_answer == 0)
			{
				g_answer = 1;
				if ((message[index] >> bits_counter) & 0b00000001)
					send_signal(pid, SIGUSR1);
				else
					send_signal(pid, SIGUSR2);
				bits_counter++;
			}
		}
	}
	usleep(100);
}
