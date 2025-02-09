/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/09 18:30:13 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	char	**map;
	void	*mlx_win;
	int		win_height;
	int		win_width;

	if (ac == 2)
	{
		if (check_map(av[1]))
		{
			mlx_ptr = mlx_init();
			map = get_map(av[1]);
			win_height = TILE_SIZE * map_line_count(av[1]);
			win_width = TILE_SIZE * (ft_strlen(map[0]) - 1);
			mlx_win = mlx_new_window(mlx_ptr, win_width, win_height,
					"Flower Lover <3");
			display_background(map, mlx_ptr, mlx_win);
			display_map(map, mlx_ptr, mlx_win);
			free_map(map);
			mlx_loop(mlx_ptr);
		}
	}
	else
		return (ft_printf("Too many or no parameters!"), 1);
}
