/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:12:58 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/24 15:10:21 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

int	g_answer;

void	check_message_received(int signal)
{
	if (signal == SIGUSR1)
		g_answer = 0;
	else
		ft_printf("Message sent with success!\n");
}

void	send_message(pid_t pid, char *message)
{
	static int	index;

	index = 0;
	while (g_answer == 0)
	{
		g_answer = 1;
		if (message[index])
		{
			// send signal to server - SIGUSR1 means sending message to server
			if (kill(pid, SIGUSR1) != 0)
				error_message("Failed to send signal!");
			index++;
		}
		else
		{
			// send signal to server - SIGUSR2 means the end of the message
			if (kill(pid, SIGUSR2) != 0)
				error_message("Failed to send signal!");
		}
	}
	usleep(100);
}

int	main(int argc, char **argv)
{
	pid_t				process_id;
	struct sigaction	client_sa;

	check_input(argc, argv);
	process_id = ft_atoi(argv[1]);
	ft_bzero(&client_sa, sizeof(struct sigaction));
	client_sa.sa_handler = &check_message_received;
	/* Receive the signals from server - 
	"The message was received with success for SIGUSR2
	and the SIGUSR1 calls for more bytes*/
	if (sigaction(SIGUSR1, &client_sa, NULL) == -1)
		error_message("Failed to set SIGUSR1");
	if (sigaction(SIGUSR2, &client_sa, NULL) == -1)
		error_message("Failed to set SIGUSR2");
	send_message(process_id, argv[2]);
	//send_message(process_id, "\n");
	return (0);
}
