/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:38:09 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 10:54:27 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Copies n bytes from src to dest safely, even if there is memory overlap.*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*unsign_dest;
	unsigned char	*unsign_src;
	size_t			i;

	unsign_dest = (unsigned char *)dest;
	unsign_src = (unsigned char *)src;
	i = 0;
	if (unsign_dest == unsign_src || n == 0)
		return (dest);
	if (unsign_dest > unsign_src)
	{
		while (n-- > 0)
		{
			unsign_dest[n] = unsign_src[n];
		}
	}
	else
	{
		while (i < n)
		{
			unsign_dest[i] = unsign_src[i];
			i++;
		}
	}
	return (dest);
}
