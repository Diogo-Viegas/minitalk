/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:33:40 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/22 10:31:19 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_strtrim() dynamically allocates memory (using malloc(3))
and returns a new string that is a copy of s1 with all characters
present in the string set removed from the beginning and the end of s1.*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	size_t	available_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	available_len = end - start + 2;
	str = (char *)malloc(sizeof(char) * available_len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], available_len);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str = "+*/hello42*-+";
// 	char *rslt = ft_strtrim(str, "+*/-");
// 	printf("Antes: %s \n Depois: %s \n", str, rslt);
// }