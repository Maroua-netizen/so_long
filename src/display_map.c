/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:11:10 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/09 16:58:42 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_img(char **map, void *mlx_ptr, void *mlx_win, t_point point)
{
	void	*img;
	int		img_height;
	int		img_width;

	if (map[point.x][point.y] == '1')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Wall.xpm",
				&img_width, &img_height);
	else if (map[point.x][point.y] == 'P')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Player.xpm", 
				&img_width, &img_height);
	else if (map[point.x][point.y] == 'C')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Collectibles.xpm", 
				&img_width, &img_height);
	else if (map[point.x][point.y] == 'E')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Exit.xpm", 
				&img_width, &img_height);
	else
		img = NULL;
	if (img)
	{
		mlx_put_image_to_window(mlx_ptr, mlx_win, img,
			img_width * point.y, img_height * point.x);
		mlx_destroy_image(mlx_ptr, img);
	}
}

void	display_map(char **map, void *mlx_ptr, void	*mlx_win)
{
	t_point	point;

	point.x = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y] != '\n')
		{
			display_img(map, mlx_ptr, mlx_win, point);
			point.y++;
		}
		point.x++;
	}
}
