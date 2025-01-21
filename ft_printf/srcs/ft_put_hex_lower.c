/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:39:15 by dangtran          #+#    #+#             */
/*   Updated: 2024/11/27 11:27:12 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_lower_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	ft_put_hex_lower(unsigned int n)
{
	size_t	len;

	len = ft_lower_len(n);
	if (n >= 16)
	{
		ft_put_hex_lower(n / 16);
		ft_put_hex_lower(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n - 10 + 'a', 1);
	}
	return (len);
}

// int main ()
// {
// 	int nbr = 789565;
// 	ft_put_hex_lower(nbr);
// 	return (0);
// } 
