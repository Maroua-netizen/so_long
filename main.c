/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/09 13:21:05 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void print_tab(char **tab)
// {
// 	int i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s", tab[i]);
// 		i++;
// 	}	
// }

int	main(void)
{
	void	*mlx_ptr;
	char	**map;
	void	*mlx_win;
	// t_data	img;
	int		win_height;
	int		win_width;

	mlx_ptr = mlx_init();
	// print_tab(get_map("map.ber"));
	check_map("map.ber");
	map = get_map("map.ber");
	win_height = 64 * map_line_count("map.ber");
	win_width = 64 * (ft_strlen(map[0]) - 1);
	// img.img_ptr = mlx_new_image(mlx_ptr, 704, 448);
	//tiles are 64x64 pixels so with the resolution above, we will have 11 tiles horizontally and 7 vertically.
	// img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, 
	// 		&img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_win = mlx_new_window(mlx_ptr, win_width, win_height, "Flower Lover <3");
	display_background(map, mlx_ptr, mlx_win);
	display_map(map, mlx_ptr, mlx_win);
	free_map(map);
	mlx_loop(mlx_ptr);
}
