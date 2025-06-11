/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:01 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/02 15:23:29 by dviegas          ###   ########.fr       */
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

int	send_message(int pid, char *str)
{
	static char	*message = NULL; // Guarda a mensagem a ser enviada (mantida entre chamadas)
	static int	s_pid = 0;       // Guarda o PID do server (mantido entre chamadas)
	static int	bits = 0;        // Conta quantos bits já foram enviados (mantida entre chamadas)

	if (str)
		message = ft_strdup(str); // Na primeira chamada, copia a mensagem para a variável estática
	if (!message)
		send_error(NULL, 0, 0);   // Se não houver mensagem, encerra com erro
	if (pid)
		s_pid = pid;              // Na primeira chamada, guarda o PID do server

	// Envia bit a bit da mensagem
	if (message[bits / BIT])     // Enquanto houver caracteres para enviar
	{
		// Verifica o valor do bit atual do caractere atual
		if (message[bits / BIT] & (128 >> (bits % BIT)))
		{
			// Se o bit for 1, envia SIGUSR2
			if (kill(s_pid, SIGUSR2) == SIG_ERROR)
				send_error(message, s_pid, SIGUSR2);
		}
		else
		{
			// Se o bit for 0, envia SIGUSR1
			if (kill(s_pid, SIGUSR1) == SIG_ERROR)
				send_error(message, s_pid, SIGUSR1);
		}
		bits++; // Avança para o próximo bit
		return (0); // Ainda há bits para enviar, retorna 0
	}
	// Se terminou de enviar todos os bits da mensagem, envia os bits do caractere nulo ('\0')
	if (!send_null(s_pid, message))
		return (0); // Ainda está enviando o caractere nulo, retorna 0

	return (free(message), 1); // Mensagem enviada com sucesso, libera memória e retorna 1
}

void	handle_signals(int sig)
{
	int	letter;

	letter = 0;
	if (sig == SIGUSR1)
		letter = send_message(0, NULL); // Envia o próximo bit/byte ao receber ACK do server
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
	signal(SIGUSR1, &handle_signals); // Registra handler para ACK do server
	signal(SIGUSR2, &handle_signals); // Registra handler para erro do server
	if (!ft_atoi(argv[1]))
	{
		ft_printf("Error: %s is an invalid PID\n", argv[1]);
		exit(1);
	}
	send_message(ft_atoi(argv[1]), argv[2]); // Envia o primeiro bit/byte
	while (1)
		pause(); // Espera sinais do server para continuar enviando
}
