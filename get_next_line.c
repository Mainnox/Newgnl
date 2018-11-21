/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:04:29 by akremer           #+#    #+#             */
/*   Updated: 2018/11/21 17:11:58 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				get_next_line(const int fd, char **line)
{
	static	char	*buf = "";
	int				ret;
	char			*tmp;
	int				size;

	ret = 1;
	if (fd < 0 || fd > 4864 || !line)
		return (-1);
	while (ret > 0)
	{
		size = size + BUFF_SIZE;
		tmp = ft_memalloc(size);
		ret = read(fd, tmp, BUFF_SIZE);
		tmp[BUFF_SIZE] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (tmp[0] == '\n' && ret == 1)
			return (0);
		if (ft_strchr(buf, '\n') != NULL)
		{
			tmp = buf;
			buf = ft_strcsub(buf, '\n');
			*line = buf;
			buf = tmp + ft_strclen(buf, '\n') + 1;
			return (1);
		}
	}
	free(tmp);
	free(buf);
	return (0);
}
