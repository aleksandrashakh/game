/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:49:34 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 09:49:36 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_resources(t_complete *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
	if (game->chip)
		mlx_destroy_image(game->mlx, game->chip);
}

int	exit_point(t_complete *game)
{
	int	line;

	free_resources(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	line = 0;
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

void	valid_path(t_complete *game);

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_complete));
	map_read(&game, argv);
	check_map(&game);
	valid_path(&game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (game.widthmap * 64),
			(game.heightmap * 64), "so_long");
	place_images(&game);
	add_graph(&game);
	mlx_hook(game.window, 2, 1L << 0, controls_working, &game);
	mlx_hook(game.window, 17, 0, exit_point, &game);
	mlx_loop(game.mlx);
}
