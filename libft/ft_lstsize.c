/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:53:45 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/17 12:23:02 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp_lst;

	count = 0;
	temp_lst = (t_list *)lst;
	while (temp_lst != NULL)
	{
		count++;
		temp_lst = temp_lst->next;
	}
	return (count);
}
