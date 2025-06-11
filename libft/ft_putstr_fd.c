/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:42:04 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 15:27:43 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_putstr_fd() writes the string s
to the specified file descriptor fd.
The string s must be null-terminated (\0).*/

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
