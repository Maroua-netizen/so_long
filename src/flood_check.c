/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:46 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/15 15:14:15 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_exit(char **map, int row, int column)
{
	if (map[row][column] == '1' || map[row][column] == 'V')
		return (0);
	if (map[row][column] == 'E')
		return (1);
	map[row][column] = 'V';
	if (check_exit(map, row + 1, column) 
		|| check_exit(map, row - 1, column) 
		|| check_exit(map, row, column + 1) 
		|| check_exit(map, row, column - 1))
		return (1);
	return (0);
}

static void	check_collectibles(char **map, int row, int column,
							int *collectibles)
{
	if (map[row][column] == '1' || map[row][column] == 'E' 
		|| map[row][column] == 'V')
		return ;
	if (map[row][column] == 'C')
		(*collectibles)++;
	map[row][column] = 'V';
	check_collectibles(map, row + 1, column, collectibles);
	check_collectibles(map, row - 1, column, collectibles);
	check_collectibles(map, row, column + 1, collectibles);
	check_collectibles(map, row, column - 1, collectibles);
}

int	flood_check(char *file_name)
{
	int		collectibles;
	char	**map;
	int		row;
	int		column;

	map = get_map(file_name);
	get_start(map, &row, &column);
	if (!check_exit(map, row, column))
		return (free_map(map), ft_printf("Error\nExit not accessible!\n"), 0);
	free_map(map);
	map = get_map(file_name);
	collectibles = 0;
	check_collectibles(map, row, column, &collectibles);
	free_map(map);
	map = get_map(file_name);
	if (collectibles != collectibles_count(map))
		return (free_map(map), 
			ft_printf("Error\nCollectibles not accessible!\n"), 0);
	return (free_map(map), 1);
}
