/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:01:11 by merboyac          #+#    #+#             */
/*   Updated: 2023/10/18 02:26:04 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len || len <= 0)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}
