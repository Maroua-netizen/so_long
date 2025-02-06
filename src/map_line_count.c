/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:05:21 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/06 18:42:10 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_line_count(char *file_name)
{
	int		fd;
	int		line_count;
	char	*next_line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file during line count");
		return (-1);
	}
	line_count = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		line_count++;
		free(next_line);
	}
	close(fd);
	return (line_count);
}
