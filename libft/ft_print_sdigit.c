/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:43:22 by sshawish          #+#    #+#             */
/*   Updated: 2025/04/29 12:48:09 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_sdigit(long n, int base, int uppercase)
{
	int		count;
	char	*symbol;

	count = 0;
	symbol = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_sdigit(-n, base, uppercase) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbol[n]));
	else
	{
		count = ft_print_sdigit(n / base, base, uppercase);
		return (count + ft_print_sdigit(n % base, base, uppercase));
	}
}
