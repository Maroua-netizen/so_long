/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:15 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/06 18:45:55 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_map(char *file_name)
{
	int		fd;
	int		line_count;
	char	**map;
	int		i;

	line_count = map_line_count(file_name);
	map = ft_calloc(line_count + 1, sizeof(char *));
	if (!map)
		return (perror("allocation failed in get_map"), NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file in get_map"), free(map), NULL);
	i = 0;
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}
