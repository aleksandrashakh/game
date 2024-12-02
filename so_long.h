/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:51:26 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 09:51:28 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include "../minilibx/mlx.h"
# include "../printf/libftprintf.h"

# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		chips;
	int		chips_graph;
	int		valid;
	int		start;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*door;
	void	*chip;
	void	*mlx;
	void	*window;

}	t_complete;

int		exit_point(t_complete *game);
int		map_read(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
int		verticalwall(t_complete *game);
int		horizontalwall(t_complete *game);
int		right_move(t_complete *game, int i, int j);
int		check_rectangular(t_complete *game, char *line);
int		width_of_map(char *string);
void	find_the_player(t_complete *game, int *x, int *y);
void	add_graph(t_complete *game);
void	place_images(t_complete *game);
void	check_map(t_complete *game);

#endif
