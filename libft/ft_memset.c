/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:57:39 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 15:53:55 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Fills the first n bytes of the memory pointed to
by s with the value (unsigned char)c.*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
// #include <stdio.h>
// int main() {
//     char str1[10] = "abcdefghi";
//     printf("Teste 1 (antes): \"%s\"\n", str1);
//     ft_memset(str1 + 2, 'X', 3);
//     printf("Teste 1 (depois): \"%s\"\n", str1);
// }