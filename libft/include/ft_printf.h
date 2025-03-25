/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:22:03 by asou              #+#    #+#             */
/*   Updated: 2025/01/29 05:12:36 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);

int		ft_putnbr_decimal(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_hex1(unsigned int n);
int		ft_putnbr_hex2(unsigned int n);
int		ft_putnbr_pointer(unsigned long n);

size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif
