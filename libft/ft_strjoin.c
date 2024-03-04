/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:01:40 by merboyac          #+#    #+#             */
/*   Updated: 2023/10/21 18:33:51 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	str = (char *)malloc(a + b + 1);
	if (!str)
		return (0);
	return (ft_strlcpy(str, s1, a + 1), ft_strlcpy(str + a, s2, b + 1), str);
}
