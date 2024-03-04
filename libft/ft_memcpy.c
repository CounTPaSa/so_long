/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:14:25 by merboyac          #+#    #+#             */
/*   Updated: 2023/10/21 17:09:04 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*source;

	dst = dest;
	source = src;
	i = -1;
	if (!src && !dest)
		return (0);
	while (++i < n)
		dst[i] = source[i];
	return (dest);
}
