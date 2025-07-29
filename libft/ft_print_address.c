/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:22:19 by sshawish          #+#    #+#             */
/*   Updated: 2025/04/29 12:47:56 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_address(void *ptr)
{
	int				count;
	unsigned long	address;

	count = 0;
	address = (unsigned long) ptr;
	if (address == 0)
		count += ft_print_str("(nil)");
	else
	{
		count += ft_print_str("0x");
		count += ft_print_udigit(address, 16, 0);
	}
	return (count);
}
