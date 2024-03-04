/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:42:02 by merboyac          #+#    #+#             */
/*   Updated: 2023/11/24 12:06:27 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

int	checkpoint(unsigned long int x)
{
	int		i;

	i = 0;
	if (x >= 16)
	{
		i += checkpoint(x / 16);
		i += ft_putchar(BASE16LOWER[x % 16]);
	}
	else
		i += ft_putchar(BASE16LOWER[x % 16]);
	return (i);
}

int	ft_point(unsigned long int x, int check)
{
	int	i;

	i = 0;
	if (check == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i += 2;
	}
	i += checkpoint(x);
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		cnt;
	size_t	base_len;
	int		tmp;

	cnt = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned int)base_len)
	{
		tmp = ft_putnbr_base(nbr / base_len, base);
		if (tmp == -1)
			return (-1);
		cnt += tmp;
	}
	if (ft_putchar(base [nbr % base_len]) == -1)
		return (-1);
	cnt++;
	return (cnt);
}

int	ft_putnbr(long int nbr)
{
	int		cnt;
	int		tmp;

	cnt = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		if (ft_putchar('-') == -1)
			return (-1);
		cnt++;
	}
	if (nbr > 9)
	{
		tmp = ft_putnbr(nbr / 10);
		if (tmp == -1)
			return (-1);
		cnt += tmp;
	}
	if (ft_putchar(nbr % 10 + '0') == -1)
		return (-1);
	cnt++;
	return (cnt);
}
