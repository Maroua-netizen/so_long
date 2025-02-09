/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:11:10 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/09 13:01:41 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*get_img(char **map, void *mlx_ptr, int i, int j)
{
	void	*img;
	int		img_height_width;

	img_height_width = 64;
	if (map[i][j] == '1')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Wall.xpm",
				&img_height_width, &img_height_width);
	else if (map[i][j] == 'P')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Player.xpm", 
				&img_height_width, &img_height_width);
	else if (map[i][j] == 'C')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Collectibles.xpm", 
				&img_height_width, &img_height_width);
	else if (map[i][j] == 'E')
		img = mlx_xpm_file_to_image(mlx_ptr, "textures/Exit.xpm", 
				&img_height_width, &img_height_width);
	else
		img = NULL;
	return (img);
}

void	display_map(char **map, void *mlx_ptr, void	*mlx_win)
{
	void	*img;
	int		i;
	int		j;
	int		img_height_width;

	img_height_width = 64;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			img = get_img(map, mlx_ptr, i, j);
			if (img)
			{
				mlx_put_image_to_window(mlx_ptr, mlx_win, img,
					img_height_width * j, img_height_width * i);
				mlx_destroy_image(mlx_ptr, img);
			}
			j++;
		}
		i++;
	}
}
