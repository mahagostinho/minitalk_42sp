/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:12:58 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/24 11:32:38 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

void	check_message_received(int signal)
{

}

void	send_message(pid_t pid, char *message)
{

}

int	main(int argc, char **argv)
{
	pid_t				process_id;
	struct sigaction	client_sa;

	check_input(argc, argv);
	process_id = ft_atoi(argv[1]);
	ft_bzero(&client_sa, sizeof(struct sigaction));
	client_sa.sa_handler = &check_message_received;
	if (sigaction(SIGUSR1, &client_sa, NULL) == -1)
		error_message("Failed to set SIGUSR1");
	if (sigaction(SIGUSR2, &client_sa, NULL) == -1)
		error_message("Failed to set SIGUSR2");
	send_message(process_id, argv[2]);
	send_message(process_id, "\n");
	while (1)
		pause();
	return (0);
}
