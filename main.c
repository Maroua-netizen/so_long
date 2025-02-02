/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/02 13:16:25 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	// t_data	img;
	void	*img;
	int		img_width;
	int		img_height;

	mlx_ptr = mlx_init();
	// img.img_ptr = mlx_new_image(mlx_ptr, 640, 360);
	// img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, 
	// 		&img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	img = mlx_xpm_file_to_image(mlx_ptr, "textures/Background.xpm", &img_width, &img_height);
	mlx_win = mlx_new_window(mlx_ptr, img_width, img_height, "Flower Lover <3");
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0, 0);
	mlx_loop(mlx_ptr);
}
