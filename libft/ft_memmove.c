/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:11:09 by merboyac          #+#    #+#             */
/*   Updated: 2023/10/20 16:39:52 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d == s)
		return (d);
	if (d > s && d < s + n)
		while (n--)
			*(d + n) = *(s + n);
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
