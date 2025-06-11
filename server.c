/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:50 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/02 14:50:44 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	signal_handler(int signum, siginfo_t *s_info, void *context)
{
	static int	dec = 255;      // Armazena o caractere reconstruído (deveria começar em 0, veja observação abaixo)
	static int	bits = 0;       // Conta quantos bits já foram recebidos
	static int	pid = 0;        // PID do client que enviou o sinal

	(void)context;
	pid = s_info->si_pid;       // Atualiza o PID do client a cada sinal recebido

	// Reconstrução do caractere:
	if (signum == SIGUSR1)
		dec ^= (128 >> bits);   // Para SIGUSR1, faz XOR com a máscara (não é o padrão, veja observação)
	else if (signum == SIGUSR2)
		dec |= (128 >> bits);   // Para SIGUSR2, seta o bit correspondente

	if (++bits == BIT)          // Quando 8 bits foram recebidos
	{
		if (dec)
			ft_printf("%c", dec); // Imprime o caractere reconstruído
		else
			ft_printf("\n");      // Se for nulo, imprime nova linha
		bits = 0;                 // Reseta contadores para o próximo caractere
		dec = 255;
	}
	// Envia ACK para o client após cada bit (deveria ser após cada byte)
	if (kill(pid, SIGUSR1) == SIG_ERROR)
	{
		kill(pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa_sig;

	sigemptyset(&sa_sig.sa_mask);
	sigaddset(&sa_sig.sa_mask, SIGINT);
	sigaddset(&sa_sig.sa_mask, SIGQUIT);
	sa_sig.sa_handler = 0;
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}
