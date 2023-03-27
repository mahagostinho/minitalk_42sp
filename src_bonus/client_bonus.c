/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:12:58 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/27 12:35:52 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

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
	return (0);
}
