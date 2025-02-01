/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/01 17:18:07 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 640, 360, "Flower Lover <3");
	img.img_ptr = mlx_new_image(mlx_ptr, 640, 360);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	mlx_loop(mlx_ptr);
}
