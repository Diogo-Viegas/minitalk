/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:05:08 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 14:37:14 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_putnbr_fd() writes the integer value n
to the specified file descriptor fd. It handles positive numbers,
negative numbers, and zero.*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nr;

	nr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nr = nr * -1;
	}
	if (nr > 9)
	{
		ft_putnbr_fd(nr / 10, fd);
		ft_putnbr_fd(nr % 10, fd);
	}
	else
		ft_putchar_fd(nr + '0', fd);
}
