/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:52:14 by val               #+#    #+#             */
/*   Updated: 2020/07/03 13:58:14 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	get_line(char *s, char **tmp, char **line)
{
	char		*result;

	if (!(result = (char *)malloc(s - *tmp + 2)))
		return (-1);
	ft_strncpy(result, *tmp, s - *tmp + 1);
	result[s - *tmp + 1] = '\0';
	if (!(s = ft_strdup(s + 1)))
	{
		free(result);
		return (-1);
	}
	free(*tmp);
	*tmp = s;
	*line = result;
	return (1);
}

static int	get_command2(ssize_t ret, char **tmp, char **line)
{
	if (*tmp && !(**tmp))
	{
		free(*tmp);
		*tmp = NULL;
		return (ret);
	}
	if (ret == 0)
	{
		*line = *tmp;
		*tmp = NULL;
		return (1);
	}
	return (ret);
}

int			get_command(const int fd, char **line)
{
	char		str[2];
	char		*s;
	static char	*sline;
	ssize_t		ret;

	if (fd < 0 || line == NULL || (read(fd, str, 0) < 0))
		return (-1);
	if (sline && (s = ft_strstr(sline, "\n")))
		return (get_line(s, &sline, line));
	if (sline == NULL)
		if (!(sline = ft_memalloc(1)))
			return (-1);
	while ((ret = read(fd, str, 1)) > 0)
	{
		str[ret] = '\0';
		if (!(s = ft_strjoin(sline, str)))
			return (-1);
		free(sline);
		sline = s;
		if ((s = ft_strstr(sline, "\n")))
			return (get_line(s, &sline, line));
	}
	return (get_command2(ret, &sline, line));
}
