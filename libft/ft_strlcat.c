/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:40:34 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 12:40:39 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function strlcat() is used to append (concatenate) the string src
 to the end of the string dst. It takes the total size of the destination
 buffer (size) as an argument and ensures that the
  result is always null-terminated (\0),
 provided there is at least one byte free in dst.
It also returns the total length of the string it tried to create,
which is the length of dst plus the length of src.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

// #include <stdio.h>
// int main ()
// {
// 	char dest[14] ="Hello ";
// 	char *src = "World";
// 	printf("---ANTES--- \n dest -> %s \n src -> %s \n",dest,src);
// 	ft_strlcat(dest,src,14);
// 	printf("---DEPOIS--- \n dest -> %s \n src -> %s \n",dest,src);
// }