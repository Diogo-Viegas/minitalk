/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:10:05 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/16 14:41:11 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function memchr() searches for the first occurrence of the byte c
 in the first n bytes of the memory area pointed to by s.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	to_find;

	str = (unsigned char *)s;
	i = 0;
	to_find = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == to_find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main ()
// {
//     char *rslt = ft_memchr("bonjour", 'o', 7);
//     printf("result -> %s \n",rslt);

// }
