/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:38:44 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/07 17:02:15 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(char *file_name)
{
	int	i;
	int	j;
	char **map;

	map = get_map(file_name);
	if (!map)
		return(0);
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' 
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				return (perror("Invalid char in map!"), free(map), 0);
			j++;
		}
		i++;
	}
	free(map);
	return (1);
}
