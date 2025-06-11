/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:22:32 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/22 12:40:39 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function strrchr() locates the last occurrence of the character 'c'
(converted to char) within the string pointed to by 's'.
The null termination character ('\0') is also considered
part of the string during the search.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main ()
// {
//     char *rslt = ft_strrchr("fewfwegwegw",103);
//     printf("-> %s \n",rslt);
// }