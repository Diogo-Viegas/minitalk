/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:19:28 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 13:43:23 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// #include <stdio.h>
// int main()
// {
//     char c = 'g';
//     char y = ft_toupper(c);
//     printf("original -> %c \nupper -> %c \n",c,y);
// }