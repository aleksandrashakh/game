/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:02:34 by alshakhp          #+#    #+#             */
/*   Updated: 2024/11/11 10:02:37 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *argv, t_complete *game)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	if (i < 4 || ft_strncmp(&argv[i - 4], ".ber", 4) != 0)
	{
		ft_printf("Error\nMap file must have a .ber extension\n");
		exit_point(game);
	}
	return (1);
}

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0' && string[width] != '\n')
		width++;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	check_rectangular(game, line);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

static void	is_empty(t_complete *game, char **argv)
{
	char	*tmp;
	char	byte;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nCan't open the file\n");
		exit_point(game);
	}
	tmp = (char *)malloc(1);
	byte = read(game->fd, tmp, 1);
	if (!byte)
	{
		ft_printf("Error\nEmpty file\n");
		exit_point(game);
	}
	free(tmp);
	close(game->fd);
}

int	map_read(t_complete *game, char **argv)
{
	char	*readmap;

	check_format(argv[1], game);
	is_empty(game, argv);
	game->fd = open(argv[1], O_RDONLY);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close(game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
