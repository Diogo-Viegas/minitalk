/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:38:04 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/18 13:25:19 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static void	send_bit(char *msg, int s_pid, int bits)
{
	int	mask;

	mask = 128 >> (bits % BIT);
	if (msg[bits / BIT] & mask)
	{
		if (kill(s_pid, SIGUSR2) == SIG_ERROR)
			send_error(msg, s_pid, SIGUSR2);
	}
	else
	{
		if (kill(s_pid, SIGUSR1) == SIG_ERROR)
			send_error(msg, s_pid, SIGUSR1);
	}
}

int	send_message(int pid, char *str)
{
	static char	*message = NULL;
	static int	s_pid = 0;
	static int	bits = 0;

	if (str && pid)
		message = ft_strdup(str);
	if (!message)
		send_error(NULL, 0, 0);
	if (pid)
		s_pid = pid;
	if (message[bits / BIT] != '\0')
	{
		send_bit(message, s_pid, bits++);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	return (free(message), 1);
}

void	handle_signals(int sig)
{
	int	letter;

	letter = 0;
	if (sig == SIGUSR1)
		letter = send_message(0, NULL);
	else if (sig == SIGUSR2)
	{
		ft_printf("Error: Server ended unexpectdly.\n");
		exit(EXIT_FAILURE);
	}
	if (letter)
	{
		ft_printf("Info: Message received successfully.\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Incorrect number of arguments!\n");
		ft_printf("Try: %s <PID> \"<MESSAGE>\"\n", argv[0]);
		exit(1);
	}
	signal(SIGUSR1, &handle_signals);
	signal(SIGUSR2, &handle_signals);
	if (!ft_atoi(argv[1]))
	{
		ft_printf("Error: %s is an invalid PID\n", argv[1]);
		exit(1);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
