/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:22:24 by dangtran          #+#    #+#             */
/*   Updated: 2024/11/25 20:50:28 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_hex_len(unsigned long n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_to_hex(unsigned long n)
{
	if (n >= 16)
	{
		ft_to_hex(n / 16);
		ft_to_hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n - 10 + 'a', 1);
	}
}

size_t	ft_ptr_hex(unsigned long ptr)
{
	size_t	res;

	res = 0;
	if (ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	res = ft_putstr_fd("0x", 1);
	ft_to_hex(ptr);
	res += ft_hex_len(ptr);
	return (res);
}
