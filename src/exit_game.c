/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:49:35 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/14 18:49:39 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	free_map(vars->map);
	exit(0);
}
