/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:51:51 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/24 15:43:36 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_strmapi() iterates over each character of the string s
 and applies the function f to each of them, passing the index of the character
  as the first argument and the character itself as the second argument.
   The result of each application of f is used to create a new "fresh"
   string (allocated with malloc(3)).
   The original string s is not modified, ensuring that the new string
   contains the applied transformations without altering the original
   input.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>
// static char	to_upper(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 	{
// 		return (c - 32);
// 	}
// 	return (c);
// }

// int	main(void)
// {
// 	const char *str1 = "hello";
// 	char *upper_str = ft_strmapi(str1, to_upper);
// 	if (upper_str)
// 	{
// 		printf("Original: %s\n", str1);
// 		printf("Maiúsculo: %s\n", upper_str);
// 		free(upper_str);
// 	}
// 	else
// 	{
// 		printf("Falha na alocação de memória para upper_str\n");
// 	}
// }