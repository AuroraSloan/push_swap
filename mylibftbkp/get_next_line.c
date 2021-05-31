/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  get_next_line.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:43:18 by jthompso          #+#    #+#             */
/*  Updated: 2021/05/16 16:20:29 by jthompso           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

static int	update_buffer(int fd, char *buf, char **s_arr, int ret)
{
	char	*tmp;

	if (!(s_arr[fd]))
		s_arr[fd] = ft_strdup("");
	if (!s_arr[fd])
		return (err_free2(s_arr[fd], buf));
	tmp = ft_strdup(s_arr[fd]);
	if (!tmp)
		return (err_free2(s_arr[fd], buf));
	free(s_arr[fd]);
	s_arr[fd] = ft_strjoin(tmp, buf);
	if (!s_arr[fd])
		return (err_free2(buf, tmp));
	free(tmp);
	return (ret);
}

static int	buffer_flow(int fd, char **s_arr)
{
	ssize_t	ret;
	char	*buf;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (err_free1(s_arr[fd]));
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (err_free2(s_arr[fd], buf));
		buf[ret] = '\0';
		ret = update_buffer(fd, buf, s_arr, ret);
		if (ret == -1)
			return (ret);
		if (ft_strchr(s_arr[fd], '\n'))
		{
			ret = 1;
			break ;
		}
	}
	free(buf);
	return (ret);
}

static int	make_new_line(int fd, char **line, char **s_arr, int ret)
{
	char	*tmp;
	size_t	len;
	int		flag;

	flag = 1;
	len = ft_find_char(s_arr[fd], '\n') - 1;
	if (!ft_strchr(s_arr[fd], '\n'))
	{
		len = ft_strlen(s_arr[fd]);
		flag--;
		if (len != 0)
			ret = 1;
	}
	*line = ft_substr(s_arr[fd], 0, len);
	if (!*line)
		return (err_free1(s_arr[fd]));
	tmp = ft_strdup(s_arr[fd] + len + flag);
	if (!tmp)
		return (err_free1(s_arr[fd]));
	free(s_arr[fd]);
	s_arr[fd] = ft_strdup(tmp);
	if (!s_arr[fd])
		return (err_free1(tmp));
	free(tmp);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*s_arr[MAX_FD];
	int			ret;

	ret = 1;
	if (!line || fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (-1);
	if (!s_arr[fd] || !ft_strchr(s_arr[fd], '\n'))
		ret = buffer_flow(fd, s_arr);
	if (ret == 0 && !s_arr[fd])
	{
		s_arr[fd] = ft_strdup("");
		if (!s_arr[fd])
			return (-1);
	}
	ret = make_new_line(fd, line, s_arr, ret);
	if (ret == 0)
	{
		free(s_arr[fd]);
		s_arr[fd] = NULL;
	}
	return (ret);
}
