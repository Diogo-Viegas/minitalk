/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:15:48 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 15:34:55 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_putendl_fd() writes the string s to the specified
file descriptor fd, followed by a newline character (\\n).
The string s must be null-terminated (\\0).*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
