#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t pid = ft_atoi(argv[1]);
	char *msg = argv[2];
	int i;
	if (argc != 3)
	{
		ft_printf("Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	i = 0;
	while (msg[i] != '\0')
		send_char(pid, msg[i++]);

	return (0);
}