/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/01 12:42:34 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 640, 360, "Flower Lover <3");
	img = mlx_new_image(mlx_ptr, 640, 360);
	mlx_loop(mlx_ptr);
}