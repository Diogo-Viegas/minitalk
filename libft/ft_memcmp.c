/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:48:11 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 10:49:56 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Compares the first n bytes of the memory areas pointed to
 by s1 and s2, byte by byte (as unsigned char).*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*unsign_s1;
	unsigned char	*unsign_s2;
	size_t			i;

	unsign_s1 = (unsigned char *)s1;
	unsign_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (unsign_s1[i] != unsign_s2[i])
			return (unsign_s1[i] - unsign_s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {   char a[] = "Hello_World";
//     char b[] = "Hello_World";
//     int x = ft_memcmp(a,b,12);

//     printf("%d \n %d \n",x,y);
// }
