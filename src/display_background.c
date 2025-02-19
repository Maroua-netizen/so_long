/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:21:54 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/09 16:01:16 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_background(char **map, void *mlx_ptr, void	*mlx_win)
{
	void	*img;
	int		i;
	int		j;
	int		img_height;
	int		img_width;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			img = mlx_xpm_file_to_image(mlx_ptr, "textures/Background.xpm", 
					&img_width, &img_height);
			if (img)
			{
				mlx_put_image_to_window(mlx_ptr, mlx_win, img,
					img_width * j, img_height * i);
				mlx_destroy_image(mlx_ptr, img);
			}
			j++;
		}
		i++;
	}
}
