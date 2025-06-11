/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:37:09 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 10:26:50 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function bzero() fills with bytes '\0'
 a region of memory..*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	char buffer1[5] = "abcde";
// 	printf("antes : %s \n", buffer1);
// 	ft_bzero(buffer1, 2);
// 	int i = 0;
// 	while (i < 5)
// 	{
// 		printf("depois: %c \n", buffer1[i]);
// 		i++;
// 	}
// }