/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:08 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 10:36:05 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main ()
// {
//     int c = 112;
//     int c2 = 50;
//     int c3 = 37;
//     if(ft_isalnum(c2))
//     {
//         printf("is alnum \n");
//     }
//     else
//     {
//         printf("isn't alnum \n");
//     }
// }