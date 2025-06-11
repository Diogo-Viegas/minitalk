/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:41:22 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/24 16:04:45 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function strnstr() searches for the first occurrence of the string
'little' within the string 'big', but the search is limited to the first
'len' characters of 'big'.
If 'little' is an empty string, 'big' is returned.
If 'little' is not found within the first 'len' characters of 'big',
the function returns NULL.*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0 || big == little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0' && big[i
				+ j] == little[j] && i + j < len)
			j++;
		if (j == little_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main ()
// {
//     char * rslt = ft_strnstr("XXWQDQWX","QD",22);
//     printf(" --> %s \n",rslt);
// }
