/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:12:55 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/14 17:47:12 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_vars *vars, int x, int y)
{
	int	row;
	int	column;

	get_start(vars->map, &row, &column);
	if (vars->map[row + x][column + y] != '1')
	{
		vars->map[row][column] = '0';
		vars->map[row + x][column + y] = 'P';
		display_background(vars->map, vars->mlx_ptr, vars->mlx_win);
		display_map(vars->map, vars->mlx_ptr, vars->mlx_win);
	}
}
