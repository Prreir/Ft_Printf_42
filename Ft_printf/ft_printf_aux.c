/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:33:29 by lugoncal          #+#    #+#             */
/*   Updated: 2022/11/28 10:33:33 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cont(int ap)
{
	int	i;

	i = 0;
	if (ap <= 0)
		i++;
	while (ap != 0)
	{
		ap /= 10;
		i++;
	}
	return (i);
}

int	ft_hex(uintptr_t ap)
{
	if (ap >= 16)
	{
		ft_hex(ap / 16);
		ft_hex(ap % 16);
	}
	else
	{
		if (ap <= 9)
			ft_char(ap + 48);
		else
			ft_char((ap - 10) + 'a');
	}
	return (1);
}

int	ft_cont_pointer(uintptr_t ap)
{
	size_t	i;

	i = 0;
	while (ap != 0)
	{
		i++;
		ap /= 16;
	}
	return (i);
}

int	ft_hex_format(unsigned int ap, const char format)
{
	if (ap >= 16)
	{
		ft_hex_format(ap / 16, format);
		ft_hex_format(ap % 16, format);
	}
	else
	{
		if (ap <= 9)
			ft_char(ap + 48);
		else
		{
			if (format == 'x')
				ft_char((ap - 10) + 'a');
			else if (format == 'X')
				ft_char((ap - 10) + 'A');
		}
	}
	return (1);
}

int	ft_cont_hexa(unsigned int ap)
{
	int	i;

	i = 0;
	while (ap != 0)
	{
		i++;
		ap /= 16;
	}
	return (i);
}
