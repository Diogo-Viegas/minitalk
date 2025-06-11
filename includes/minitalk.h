/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:39:43 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/02 13:40:41 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"

# define BIT 8
# define SIG_ERROR -1

void	send_error(char *message, int pid, int sig);
void	handler_sig(int sig);
int		send_message(int pid, char *str);
int		send_null(int pid, char *message);

#endif
