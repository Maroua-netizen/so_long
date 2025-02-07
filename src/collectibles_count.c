/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:10:47 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/07 13:38:57 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collectibles_count(char **map)
{
	int	i;
	int	j;
	int	collectibles;

	collectibles = 0;
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles < 1)
		return (perror("No collectibles in map!"), 0);
	return (collectibles);
}
