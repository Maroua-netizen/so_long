/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:13 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/14 17:51:49 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126)
		move_player(vars, -1, 0);
	else if (keycode == 1 || keycode == 125)
		move_player(vars, 1, 0);
	else if (keycode == 0 || keycode == 123)
		move_player(vars, 0, -1);
	else if (keycode == 2 || keycode == 124)
		move_player(vars, 0, 1);
	return (0);
}
