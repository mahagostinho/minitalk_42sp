/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:13:03 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/27 12:36:14 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

int	main(void)
{
	struct sigaction	server_sa;
	pid_t				process_id;
	sigset_t			sig_mask;

	ft_bzero(&server_sa, sizeof(struct sigaction));
	sigemptyset(&sig_mask);
	sigaddset(&sig_mask, SIGUSR1);
	sigaddset(&sig_mask, SIGUSR2);
	server_sa.sa_flags = SA_SIGINFO;
	server_sa.sa_mask = sig_mask;
	server_sa.sa_sigaction = print_message;
	process_id = getpid();
	ft_printf("PID: %d\n", process_id);
	if (sigaction(SIGUSR1, &server_sa, NULL) == -1)
		error_message("Failed to set SIGUSR1");
	if (sigaction(SIGUSR2, &server_sa, NULL) == -1)
		error_message("Failed to set SIGUSR2");
	while (1)
		pause();
	return (0);
}
