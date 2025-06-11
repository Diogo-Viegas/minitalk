/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:56:49 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/21 11:52:29 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function calloc() allocates memory for an array of elements,
 initializing all of its bytes to zeros ('\0').
It is especially useful when you need memory for multiple items
 and want to ensure that they start with null values.*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
	{
		return (NULL);
	}
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}

// #include <stdint.h>
// #include <stdio.h>

// int	main(void)
// {
// 	void	*rslt;

// 	rslt = ft_calloc(SIZE_MAX, SIZE_MAX);
// 	printf("-> %p", rslt);
// }
