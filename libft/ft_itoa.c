/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:13:52 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/17 08:54:11 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_itoa() dynamically allocates (using malloc(3))
and returns a new string terminated with '\0' that represents the integer
value n passed as an argument.
It must support negative numbers.*/

#include "libft.h"

static size_t	count_digits(long int nb)
{
	size_t	i;

	i = 1;
	if (nb == 0)
		return (1);
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*n_str;
	size_t		nbr_digits;
	long int	num;

	num = (long int)n;
	if (n < 0)
		num = num * -1;
	nbr_digits = count_digits(num);
	if (n < 0)
		nbr_digits++;
	n_str = (char *)malloc(sizeof(char) * (nbr_digits + 1));
	if (!n_str)
		return (NULL);
	n_str[nbr_digits] = 0;
	while (nbr_digits > 0)
	{
		nbr_digits--;
		n_str[nbr_digits] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		n_str[0] = '-';
	return (n_str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str = ft_itoa(-2147483648);
// 	printf("string -> %s \n", str);
// }