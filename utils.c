/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:27:44 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/17 17:28:09 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	send_error(char *message, int pid, int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Error: Sending SIGUSR1 signal to PID %i failed\n", pid);
	else if (sig == SIGUSR2)
		ft_printf("Error: Sending SIGUSR2 signal to PID %i failed\n", pid);
	else
		ft_printf("Error: Sending unknown signal to PID %i\n", pid);
	if (message)
	{
		free(message);
	}
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *message)
{
	static int	index = 0;

	if (index++ != BIT)
	{
		if (kill(pid, SIGUSR1) == SIG_ERROR)
			send_error(message, pid, SIGUSR1);
		return (0);
	}
	return (1);
}
