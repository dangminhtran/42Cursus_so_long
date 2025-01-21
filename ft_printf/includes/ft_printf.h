/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:22:56 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 15:25:25 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_put_hex_lower(unsigned int n);
size_t	ft_put_hex_upper(unsigned int n);
size_t	ft_put_unsigned(unsigned int n);
size_t	ft_ptr_hex(unsigned long ptr);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *format, ...);
int	ft_strcmp(char *str1, char *str2);

#endif