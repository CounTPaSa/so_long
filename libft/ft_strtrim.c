/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:29 by merboyac          #+#    #+#             */
/*   Updated: 2023/10/21 14:47:08 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*trim;

	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, *end))
		end--;
	trim = ft_substr(s1, start - s1, end - start + 1);
	if (!trim)
		return (NULL);
	return (trim);
}
