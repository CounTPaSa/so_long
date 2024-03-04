/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:17:20 by merboyac          #+#    #+#             */
/*   Updated: 2023/12/02 16:41:11 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_copy_to_stash(char *stash, char *buf)
{
	char	*res;

	if (!stash && buf)
		return (ft_strdup(buf));
	res = ft_strjoin(stash, buf);
	ft_free_stash(&stash, 0);
	return (res);
}

static int	ft_have_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		if (s[i++] == '\n')
			return (1);
	return (0);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (ft_free_stash(&stash, 0));
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free_stash(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_recreate_stash(char *stash)
{
	size_t	i;
	char	*rslt;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	rslt = ft_substr(stash, i + 1, ft_strlen(stash));
	ft_free_stash(&stash, 0);
	return (rslt);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*stash = NULL;
	char			*line;
	long			rtn;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stash(&stash, 0));
	rtn = 1;
	while (rtn > 0)
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		if ((rtn <= 0 && !stash) || rtn == -1)
			return (ft_free_stash(&stash, 0));
		buf[rtn] = '\0';
		stash = ft_copy_to_stash(stash, buf);
		if (ft_have_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}
