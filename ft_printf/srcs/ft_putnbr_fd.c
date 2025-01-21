/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:28:12 by dangtran          #+#    #+#             */
/*   Updated: 2024/11/27 10:55:38 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_len(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	size_t	len;

	nbr = ft_itoa(n);
	len = ft_putstr_fd(nbr, fd);
	free(nbr);
	return (len);
}
