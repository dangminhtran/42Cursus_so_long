/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:00:52 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/21 14:04:25 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_width(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		i--;
	if (i >= 300)
	{
		ft_printf("Error\nMap is too wide\n");
		exit(0);
	}
	return (i);
}

static int	add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	game->height++;
	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp)
		return (0);
	tmp[game->height] = NULL;
	while (i < game->height - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

void	is_rectangular(t_game *game, int x)
{
	int	i;

	i = 0;
	if (game->height >= 30)
	{
		ft_printf("Error\nMap is too tall\n");
		exit_game(game);
	}
	while (i < game->height)
	{
		if (map_width(game->map[i]) != x)
		{
			ft_printf("Error\nMap is not rectangular\n");
			exit_game(game);
		}
		i++;
	}
}

void	find_player_position(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (game->map[height][width] != '\0')
		{
			if (game->map[height][width] == 'P')
			{
				game->x_axis = width;
				game->y_axis = height;
				return ;
			}
			width++;
		}
		height++;
	}
	ft_printf("Error\n No player found on the map\n");
	exit_game(game);
}

int	read_map(t_game *game, char **argv)
{
	char	*stash;

	if (ft_strlen(argv[1]) < 5
		|| ft_strcmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber"))
	{
		ft_printf("Error\nInvalid map file\n");
		exit(0);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		stash = get_next_line(game->fd);
		if (!add_line(game, stash))
			break ;
	}
	close(game->fd);
	if (!game->map)
		return (0);
	is_rectangular(game, map_width(game->map[0]));
	game->width = map_width(game->map[0]);
	find_player_position(game);
	return (1);
}
