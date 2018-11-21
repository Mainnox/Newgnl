/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:39:02 by akremer           #+#    #+#             */
/*   Updated: 2018/11/21 17:09:57 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	const int fd = open(argv[1], O_RDONLY);
	char		**line;

	(void)argc;
	if (!(line = (char**)malloc(sizeof(**line) * 2)))
		return (0);
	while (get_next_line(fd, line))
	{
		ft_putendl(line[0]);
		free(line[0]);
	}
	return (1);
}
