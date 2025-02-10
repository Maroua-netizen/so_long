/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/10 13:36:19 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	char	**map;

	if (ac == 2)
	{
		if (!check_map(av[1]))
			exit(1);
		vars.mlx_ptr = mlx_init();
		map = get_map(av[1]);
		vars.mlx_win = mlx_new_window(vars.mlx_ptr, 
				TILE_SIZE * (ft_strlen(map[0]) - 1), 
				TILE_SIZE * map_line_count(av[1]), "Flower Lover <3");
		display_background(map, vars.mlx_ptr, vars.mlx_win);
		display_map(map, vars.mlx_ptr, vars.mlx_win);
		// mlx_key_hook(vars.mlx_win, key_hook, &vars);
		free_map(map);
		mlx_loop(vars.mlx_ptr);
	}
	else
		return (ft_printf("Too many or no parameters!"), 1);
}
