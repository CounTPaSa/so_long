/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:41:16 by merboyac          #+#    #+#             */
/*   Updated: 2023/11/24 12:09:07 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	check_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_point(va_arg(args, unsigned long int), 1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), BASE10));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned long int), BASE16LOWER));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned long int), BASE16UPPER));
	else if (format == '%')
	{
		if (ft_putchar('%') == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		p_return;
	int		i;
	int		temp;

	p_return = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			temp = check_format(format[i + 1], args);
			if (temp == -1)
				return (-1);
			p_return += (temp - 1);
			i++;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		p_return++;
		i++;
	}
	va_end(args);
	return (p_return);
}
