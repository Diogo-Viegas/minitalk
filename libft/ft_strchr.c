/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:47:20 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/24 15:42:29 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*"Search for the first occurrence of the
character 'c' in the string 's' and
return a pointer to it.
If the character is not found, return NULL.
The NULL terminator "\0" is part of the string !!!
"*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while ((*s != '\0') && (*s != uc))
	{
		s++;
	}
	if (*s == uc)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

// #include <stdio.h>
// int main ()
// {
// 	char *rslt = ft_strchr("hello world", 'w' + 256);
// 	printf("%s \n",rslt);
// }