/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:31 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/15 15:41:40 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_vars *vars);
static void	move_player(t_vars *vars, int x, int y);

int	main(int ac, char **av)
{
	t_vars	vars;
	int		win_height;
	int		win_width;

	if (ac != 2)
		return (ft_printf("Error\nToo many or no parameters!\n"), 1);
	check_map(av[1]);
	vars.mlx_ptr = mlx_init();
	vars.map = get_map(av[1]);
	win_height = TILE_SIZE * map_line_count(av[1]);
	win_width = TILE_SIZE * (ft_strlen(vars.map[0]) - 1);
	if (win_height > SCREEN_HEIGHT || win_width > SCREEN_WIDTH)
		return (ft_printf("Error\nWindow too big for screen!\n"),
			free_map(vars.map), 1);
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, win_width, 
			win_height, "Flower Lover <3");
	display_background(vars.map, vars.mlx_ptr, vars.mlx_win);
	display_map(vars.map, vars.mlx_ptr, vars.mlx_win);
	vars.moves = 0;
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, exit_game, &vars);
	mlx_loop(vars.mlx_ptr);
	free_map(vars.map);
}

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_game(vars);
	if (keycode == 13 || keycode == 126)
		move_player(vars, -1, 0);
	else if (keycode == 1 || keycode == 125)
		move_player(vars, 1, 0);
	else if (keycode == 0 || keycode == 123)
		move_player(vars, 0, -1);
	else if (keycode == 2 || keycode == 124)
		move_player(vars, 0, 1);
	return (0);
}

static void	move_player(t_vars *vars, int x, int y)
{
	int	row;
	int	column;

	get_start(vars->map, &row, &column);
	if (vars->map[row + x][column + y] == 'E' && !collectibles_count(vars->map))
		exit_game(vars);
	if (vars->map[row + x][column + y] != '1' 
		&& vars->map[row + x][column + y] != 'E')
	{
		vars->map[row][column] = '0';
		vars->map[row + x][column + y] = 'P';
		display_background(vars->map, vars->mlx_ptr, vars->mlx_win);
		display_map(vars->map, vars->mlx_ptr, vars->mlx_win);
		vars->moves++;
		ft_printf("%d\n", vars->moves);
	}
}
