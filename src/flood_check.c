/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:46 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 11:55:31 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_exit(char **map, t_point size, int row, int column)
{
	if (row < 0 || row >= size.x || column < 0 || column >= size.y 
		|| map[row][column] == '1' || map[row][column] == 'V')
		return (0);
	if (map[row][column] == 'E')
		return (1);
	map[row][column] = 'V';
	if (check_exit(map, size, row + 1, column) 
		|| check_exit(map, size, row - 1, column) 
		|| check_exit(map, size, row, column + 1) 
		|| check_exit(map, size, row, column - 1))
		return (1);
	return (0);
}

static void	check_collectibles(char **map, t_point size, t_point begin, 
								int *collectibles)
{
	t_point	new_point;

	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y 
		|| map[begin.x][begin.y] == '1' || map[begin.x][begin.y] == 'V')
		return ;
	if (map[begin.x][begin.y] == 'C')
		(*collectibles)++;
	map[begin.x][begin.y] = 'V';
	new_point.x = begin.x + 1;
	new_point.y = begin.y;
	check_collectibles(map, size, new_point, collectibles);
	new_point.x = begin.x - 1;
	new_point.y = begin.y;
	check_collectibles(map, size, new_point, collectibles);
	new_point.x = begin.x;
	new_point.y = begin.y + 1;
	check_collectibles(map, size, new_point, collectibles);
	new_point.x = begin.x;
	new_point.y = begin.y - 1;
	check_collectibles(map, size, new_point, collectibles);
}

int	flood_check(char *file_name, t_point size, t_point begin)
{
	int		collectibles;
	char	**map;

	map = get_map(file_name);
	if (!check_exit(map, size, begin.x, begin.y))
		return (free_map(map), perror("Error\nExit not accessible!"), 0);
	free_map(map);
	map = get_map(file_name);
	collectibles = 0;
	check_collectibles(map, size, begin, &collectibles);
	free_map(map);
	map = get_map(file_name);
	if (collectibles != collectibles_count(map))
		return (free_map(map), perror("Error\nCollectibles not accessible!"), 0);
	return (free_map(map), 1);
}
