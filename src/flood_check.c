/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:46 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/07 19:08:57 by mmounsif         ###   ########.fr       */
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
    if( check_exit(map, size, row + 1, column) ||
    check_exit(map, size, row - 1, column) ||
    check_exit(map, size, row, column + 1) ||
    check_exit(map, size, row, column - 1))
		return (1);
	return (0);
}

static void	check_collectibles(char **map, t_point size, int row, int column, int *collectibles)
{
	if (row < 0 || row >= size.x || column < 0 || column >= size.y 
		|| map[row][column] == '1' || map[row][column] == 'V')
		return;
	if (map[row][column] == 'C')
		(*collectibles)++;
	map[row][column] = 'V';
    check_collectibles(map, size, row + 1, column, collectibles);
    check_collectibles(map, size, row - 1, column, collectibles);
    check_collectibles(map, size, row, column + 1, collectibles);
    check_collectibles(map, size, row, column - 1, collectibles);
}

int  flood_check(char *file_name, t_point size, t_point begin)
{
	int		collectibles;
	char	**map;
	
	map = get_map(file_name);
	if (!check_exit(map, size, begin.x, begin.y))
		return (free(map), perror("Exit not accessible!"), 0);
	free(map);
	map = get_map(file_name);
	collectibles = 0;
	check_collectibles(map, size, begin.x, begin.y, &collectibles);
	free(map);
	map = get_map(file_name);
	if (collectibles != collectibles_count(map))
		return (free(map), perror("Collectibles not accessible!"), 0);
	return (free(map), 1);
}
