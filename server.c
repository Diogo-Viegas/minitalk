/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:59:40 by dviegas           #+#    #+#             */
/*   Updated: 2025/05/26 13:42:13 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signum)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	if (signum == SIGUSR2)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1,sig_handler);
	signal(SIGUSR2,sig_handler);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}

	return (0);
}