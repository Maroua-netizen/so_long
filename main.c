/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/14 17:38:10 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2)
	{
		check_map(av[1]);
		vars.mlx_ptr = mlx_init();
		vars.map = get_map(av[1]);
		vars.mlx_win = mlx_new_window(vars.mlx_ptr, 
				TILE_SIZE * (ft_strlen(vars.map[0]) - 1), 
				TILE_SIZE * map_line_count(av[1]), "Flower Lover <3");
		display_background(vars.map, vars.mlx_ptr, vars.mlx_win);
		display_map(vars.map, vars.mlx_ptr, vars.mlx_win);
		mlx_key_hook(vars.mlx_win, key_hook, &vars);
		mlx_loop(vars.mlx_ptr);
		free_map(vars.map);
	}
	else
		return (ft_printf("Too many or no parameters!"), 1);
}
