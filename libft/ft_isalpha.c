/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:21:36 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 10:38:39 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main ()
// {
//     int a = 48;
//     if(ft_isalpha(a))
//         printf("is alpha \n");
//     else
//         printf("isn't alpha \n");
// }