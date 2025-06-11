/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:00:23 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/24 15:43:17 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_striteri() iterates over each character
of the string s and applies the function f to each of them.
 Unlike ft_striter(), the function f receives the index of
 the character in the string as the first argument
 (of type unsigned int) and the address of the character
 (char *) as the second argument, allowing modifications based
 on the position.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void print_with_index(unsigned int index, char *c) {
//     printf("Na posição %u, o caractere é '%c'\n", index, *c);
// }

// int main() {
//     char my_string[] = "abc";
//     printf("Testando ft_striteri:\n");
//     ft_striteri(my_string, print_with_index);
//     return (0);
// }