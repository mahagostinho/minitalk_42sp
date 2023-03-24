/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:31:55 by marcarva          #+#    #+#             */
/*   Updated: 2023/03/24 11:32:28 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

void	error_message(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

int	process_id_is_digit(char *str_pid)
{
	int	i;

	i = 0;
	while (str_pid[i])
	{
		if (ft_isdigit(str_pid[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_input(int argc, char **argv)
{
	if (argc != 3)
		error_message("Error!\nUse: ./client <PID> <message>");
	if ((!process_id_is_digit(argv[1])) && (ft_atoi(argv[1]) <= 0))
		error_message("Invalid process ID!");
}
