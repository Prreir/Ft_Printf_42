/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:44:16 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/29 14:44:18 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *ap)
{
	int	i;

	i = 0;
	if (!ap)
		return (ft_str("(null)"));
	while (ap[i] != '\0')
	{
		write(1, &ap[i], 1);
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long long ap)
{
	int	i;

	if (ap == 0)
		return (ft_str("(nil)"));
	else
	{
		i = ft_str("0x");
		ft_hex(ap);
	}
	return (i += ft_cont_pointer(ap));
}

int	ft_nb(int ap)
{
	int	i;

	i = ft_cont(ap);
	if (ap == -2147483648)
	{
		ft_char('-');
		ft_char('2');
		ap = 147483648;
	}
	if (ap < 0)
	{
		ft_char('-');
		ap = -ap;
	}
	if (ap >= 10)
	{
		ft_nb(ap / 10);
		ap %= 10;
	}
	if (ap < 10)
		ft_char(ap + 48);
	return (i);
}

int	ft_nbu(unsigned int ap)
{
	int	i;

	i = 0;
	if (ap >= 10)
	{
		i += ft_nb(ap / 10);
		ap %= 10;
	}
	if (ap < 10)
		i += ft_char(ap + 48);
	return (i);
}

int	ft_hexa(unsigned int ap, const char format)
{
	if (ap == 0)
		return (ft_char('0'));
	else
		ft_hex_format(ap, format);
	return (ft_cont_hexa(ap));
}
