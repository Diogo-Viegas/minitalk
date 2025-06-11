/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:39:38 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 10:56:47 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_putchar_fd() writes the character c to the
specified file descriptor fd. This allows directing the output
to files, pipes, or other streams.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
