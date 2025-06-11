/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:37:29 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 17:14:44 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function strdup() creates an exact copy of the string s.
It dynamically allocates enough memory to store this copy
(including the null-terminating character) using the malloc() function.*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*copy;
	int		i;

	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// #include <stdio.h>
// int main()
// {
//     printf("copy -> %s \n",ft_strdup("Hello 42!"));
// }