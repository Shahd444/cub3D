/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:07:57 by sshawish          #+#    #+#             */
/*   Updated: 2025/04/29 12:48:16 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_print_str("(null)"));
	while (*str)
	{
		count += ft_print_char((int) *(str++));
	}
	return (count);
}
