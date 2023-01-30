/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:17:19 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/22 14:17:20 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char ap)
{
	write (1, &ap, 1);
	return (1);
}

int	ft_format(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (format == 's')
		return (ft_str(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_pointer(va_arg(ap, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_nb(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_nbu(va_arg(ap, unsigned int)));
	else if (format == 'x')
		return (ft_hexa(va_arg(ap, unsigned int), format));
	else if (format == 'X')
		return (ft_hexa(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_format(ap, format[i + 1]);
			i++;
		}
		else
			count += ft_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
