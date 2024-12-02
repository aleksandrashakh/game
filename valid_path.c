/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:00 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 14:22:02 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map_copy, t_complete *game)
{
	int	i;

	i = 0;
	while (i < game->heightmap)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

char	**copy_map(t_complete *game)
{
	int		i;
	int		j;
	char	**map_copy;

	map_copy = (char **)malloc(sizeof(char *) * game->heightmap);
	if (!map_copy)
	{
		ft_printf("Error\nMemory allocation failed for map copy");
		exit_point(game);
	}
	i = 0;
	while (i < game->heightmap)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * (game->widthmap + 1));
		j = 0;
		while (j < game->widthmap)
		{
			map_copy[i][j] = game->map[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	return (map_copy);
}

static void	flood_fill(t_complete *game, char **map_copy, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->heightmap || x >= game->widthmap)
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'E')
	{
		game->valid = 1;
		return ;
	}
	map_copy[y][x] = 'V';
	flood_fill(game, map_copy, y + 1, x);
	flood_fill(game, map_copy, y - 1, x);
	flood_fill(game, map_copy, y, x + 1);
	flood_fill(game, map_copy, y, x - 1);
}

static void	flood_fill1(t_complete *game, char **map_copy1, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->heightmap || x >= game->widthmap)
		return ;
	if (map_copy1[y][x] == '1' || map_copy1[y][x] == 'V' ||
		map_copy1[y][x] == 'E')
		return ;
	if (map_copy1[y][x] == 'C')
		game->columncount--;
	map_copy1[y][x] = 'V';
	flood_fill1(game, map_copy1, y + 1, x);
	flood_fill1(game, map_copy1, y - 1, x);
	flood_fill1(game, map_copy1, y, x + 1);
	flood_fill1(game, map_copy1, y, x - 1);
}

void	valid_path(t_complete *game)
{
	int		y;
	int		x;
	char	**map_copy;

	map_copy = copy_map(game);
	find_the_player(game, &x, &y);
	flood_fill(game, map_copy, y, x);
	free_map(map_copy, game);
	if (game->valid == 1)
	{
		map_copy = copy_map(game);
		flood_fill1(game, map_copy, y, x);
	}
	free_map(map_copy, game);
	if (game->columncount != 0)
	{
		ft_printf("No valid path to exit with all chips collected\n");
		exit_point(game);
	}
	ft_printf("Map is playable. Start: \n");
}
