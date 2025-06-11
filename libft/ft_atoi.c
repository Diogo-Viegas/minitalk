/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:46:39 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/15 12:25:12 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function atoi() converts the beginning of a string 
(sequence of characters) into an integer of type int.*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main ()
// {
//     int res = ft_atoi("-+123");
//     int res2 = ft_atoi("dsfsd");
//     int res3 = ft_atoi("+324234");

// 	int res4 = atoi("-+123");
// 	int res5 = atoi("dsfsd");
// 	int res6 = atoi("+324234");

//     printf("my atoi: %d %d %d \n",res,res2,res3);
// 		printf("real atoi: %d %d %d \n",res4,res5,res6);
// }