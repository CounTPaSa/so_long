/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:34:21 by merboyac          #+#    #+#             */
/*   Updated: 2023/10/21 17:14:21 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_getnbr(int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c < 0 || c > 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int		nblen;
	char	*buffer;
	long	number;

	nblen = ft_getnbr(nbr);
	number = nbr;
	if (number < 0)
	{
		nblen++;
		number = -number;
	}
	buffer = malloc (sizeof (char) * nblen + 1);
	if (!buffer)
		return (NULL);
	buffer[nblen] = '\0';
	while (number > 0)
	{
		buffer[--nblen] = number % 10 + 48;
		number /= 10;
	}
	if (nbr < 0)
		buffer[0] = '-';
	if (nbr == 0)
		buffer [0] = '0';
	return (buffer);
}
