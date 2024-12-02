/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:17:35 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 11:17:37 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	keyboard_a(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i--;
	if (game->map[j][i] == '1')
	{
		ft_printf("Blocked by a wall at (%d, %d)\n", i, j);
		return (0);
	}
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->chips);
	return (1);
}

static int	keyboard_d(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i++;
	if (game->map[j][i] == '1')
	{
		ft_printf("Blocked by a wall at (%d, %d)\n", i, j);
		return (0);
	}
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i - 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->chips);
	return (1);
}

static int	keyboard_w(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j--;
	if (game->map[j][i] == '1')
	{
		ft_printf("Blocked by a wall at (%d, %d)\n", i, j);
		return (0);
	}
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->chips);
	return (1);
}

static int	keyboard_s(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j++;
	if (game->map[j][i] == '1')
	{
		ft_printf("Blocked by a wall at (%d, %d)\n", i, j);
		return (0);
	}
	k = right_move(game, i, j);
	if (!k)
		return (0);
	game->map[j - 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->chips);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	works = 0;
	game->chips_graph = game->chips;
	if (command == ESC)
		exit_point(game);
	else if (command == W)
		works = keyboard_w(game);
	else if (command == S)
		works = keyboard_s(game);
	else if (command == A)
		works = keyboard_a(game);
	else if (command == D)
		works = keyboard_d(game);
	if (works)
	{
		add_graph(game);
		game->start = 1;
	}
	return (1);
}
