/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:18 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/22 14:10:25 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list ap, const char format);
int	ft_char(char ap);
int	ft_str(char *format);
int	ft_pointer(unsigned long long ptr);
int	ft_nb(int ap);
int	ft_nbu(unsigned int ap);
int	ft_hexa(unsigned int num, const char format);
int	ft_cont(int ap);
int	ft_hex(uintptr_t ap);
int	ft_cont_pointer(uintptr_t ap);
int	ft_hex_format(unsigned int ap, const char format);
int	ft_cont_hexa(unsigned int ap);

#endif
