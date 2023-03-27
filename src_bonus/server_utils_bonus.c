/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:37:04 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/27 12:36:21 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

void	error_message(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	print_message(int signal, siginfo_t *info, void *ucontext)
{
	static char	letter;
	static int	shift;

	(void)ucontext;
	if (signal == SIGUSR1)
		letter += (0b0000001 << shift);
	if (shift == 7)
	{
		if (letter)
			ft_putchar_fd(letter, 1);
		else
		{
			if (kill(info->si_pid, SIGUSR2) != 0)
				error_message("Failed to send signal!");
			ft_putchar_fd('\n', 1);
		}
		letter = 0;
		shift = 0;
	}
	else
		shift++;
	if (kill(info->si_pid, SIGUSR1) != 0)
		error_message("Failed to send signal!");
}
