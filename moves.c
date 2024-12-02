/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:05:58 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/14 15:06:00 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_e(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->chips != 0)
		{
			ft_printf("\nSorry, you died!\n");
			exit_point(game);
			return ;
		}
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
}

void	is_zero(t_complete *game, int i, int j)
{
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
		ft_printf("New position: (%d, %d)\n", game->x_axis,
			game->y_axis);
	}
}

void	is_c(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->chips--;
		game->counter++;
		game->chips_graph = game->chips;
		ft_printf("Collcted on: (%d, %d)\n", game->x_axis, game->y_axis);
	}
}

int	right_move(t_complete *game, int i, int j)
{
	is_e(game, i, j);
	is_zero(game, i, j);
	is_c(game, i, j);
	return (1);
}

void	find_the_player(t_complete *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (game->map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return ;
}
