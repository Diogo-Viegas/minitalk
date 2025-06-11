/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:40:35 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/24 16:06:54 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_substr() dynamically allocates memory
(using malloc(3)) and returns a new substring of the string s.
The substring starts at the index start and has a
maximum length of len characters.
If the resulting substring is shorter than len
(due to reaching the end of s),
only the available portion will be returned.*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
		str[len] = s[start + len];
	return (str);
}
// #include <stdio.h>
// int main()
// {
// 	char *full_str = "ewfewhello";
// 	char *rslt = ft_substr(full_str,5,10);
// 	printf("full string -> %s \n sub string -> %s \n",full_str,rslt);
// }