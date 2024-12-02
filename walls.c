/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:09:53 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 14:09:56 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

int	horizontalwall(t_complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' || game->map[game->heightmap - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_rectangular(t_complete *game, char *line)
{
	if (game->heightmap == 0)
		game->widthmap = width_of_map(line);
	if (width_of_map(line) != game->widthmap)
	{
		ft_printf("Error\nMap is not rectangular\n");
		free(line);
		exit_point(game);
	}
	return (0);
}
