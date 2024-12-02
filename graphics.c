/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:34 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 10:51:37 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_images(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &i, &j);
	if (!game->floor)
		ft_printf("Error loading floor.\n");
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/walls1.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/oran001.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit001.xpm", &i, &j);
	game->door = mlx_xpm_file_to_image(game->mlx,
			"textures/door.xpm", &i, &j);
	game->chip = mlx_xpm_file_to_image(game->mlx,
			"textures/book001.xpm", &i, &j);
	if (!game->floor || !game->wall || !game->player
		|| !game->exit || !game->chip)
	{
		ft_printf("Error loading textures.\n");
		exit_point(game);
	}
}

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->window, game->player, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->window, game->chip, width * 64, height * 64);
	game->chips++;
}

void	check(char position, t_complete *game, int height, int width)
{
	if (position == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->wall, width * 64, height * 64);
	if (position == 'C')
		place_collectable(game, height, width);
	if (position == 'P')
		place_player(game, height, width);
	if (position == 'E')
	{
		if (game->chips_graph == 0 && game->start != 0)
			mlx_put_image_to_window(game->mlx,
				game->window, game->door, width * 64,
				height * 64);
		else
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->exit, width * 64, height * 64);
		}
	}
	if (position == '0')
		mlx_put_image_to_window(game->mlx,
			game->window, game->floor, width * 64, height * 64);
}

void	add_graph(t_complete *game)
{
	int	height;
	int	width;

	game->chips = 0;
	height = 0;
	mlx_clear_window(game->mlx, game->window);
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			check(game->map[height][width], game, height, width);
			width++;
		}
		height++;
	}
}
