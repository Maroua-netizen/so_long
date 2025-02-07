/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:30 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/07 15:43:44 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	walls_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (perror("Top wall breached!"), 0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			return (perror("Side walls breached!"), 0);
		i++;
	}
	j = 0;
	while (map[i - 1][j] != '\n')
	{
		if (map[i - 1][j] != '1')
			return (perror("Bottom wall breached!"), 0);
		j++;
	}
	return (1);
}
