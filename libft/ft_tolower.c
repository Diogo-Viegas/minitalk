/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:36 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 13:42:24 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

// #include <stdio.h>
// int main()
// {
//     char c = 'G';
//     char y = ft_tolower(c);
//     printf("original -> %c \nlower -> %c \n",c,y);
// }