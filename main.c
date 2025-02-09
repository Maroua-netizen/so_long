/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/09 13:51:57 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	char	**map;
	void	*mlx_win;
	int		win_height;
	int		win_width;

	if (check_map("map.ber"))
	{
		mlx_ptr = mlx_init();
		map = get_map("map.ber");
		win_height = 64 * map_line_count("map.ber");
		win_width = 64 * (ft_strlen(map[0]) - 1);
		mlx_win = mlx_new_window(mlx_ptr, win_width, win_height,
				"Flower Lover <3");
		display_background(map, mlx_ptr, mlx_win);
		display_map(map, mlx_ptr, mlx_win);
		free_map(map);
		mlx_loop(mlx_ptr);
	}
}
