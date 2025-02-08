/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:38:44 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 17:06:57 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	char_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' 
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (ft_printf("Error\nInvalid char in map!"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	exit_start_check(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	start;

	exit = 0;
	start = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				start++;
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1 || start != 1)
		return (ft_printf("Error\nMore than one/no start/exit in the map!"), 0);
	return (1);
}

static int	rectangular_check(char **map)
{
	int		i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (ft_printf("Error\nMap not rectangular!"), 0);
		i++;
	}
	return (1);
}

static int	walls_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (ft_printf("Error\nTop wall breached!"), 0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			return (ft_printf("Error\nSide walls breached!"), 0);
		i++;
	}
	j = 0;
	while (map[i - 1][j] != '\n')
	{
		if (map[i - 1][j] != '1')
			return (ft_printf("Error\nBottom wall breached!"), 0);
		j++;
	}
	return (1);
}

int	check_map(char *file_name)
{
	char	**map;

	map = get_map(file_name);
	if (!map)
		return (perror("Couldn't get map during check!"), 0);
	if (!char_check(map) || !exit_start_check(map)
		|| !collectibles_count(map) || !rectangular_check(map) 
		|| !walls_check(map) || !flood_check(file_name))
		return (free_map(map), 0);
	return (free_map(map), 1);
}
