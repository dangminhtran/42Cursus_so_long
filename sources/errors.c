/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:31:16 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/21 17:10:05 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../includes/so_long.h"

static int	is_horizontal_wall(t_game *game)
{
	int	i;
	int	j;

	i = game->width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	is_vertical_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->height;
	while (i < j)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' && game->map[height][width] != '0'
		&& game->map[height][width] != 'C' && game->map[height][width] != 'E'
		&& game->map[height][width] != 'P' && game->map[height][width] != '\n')
	{
		ft_printf("Error\nBad input here : %c\n", game->map[height][width]);
		exit_game(game);
	}
	if (game->map[height][width] == 'C')
		game->collectables++;
	if (game->map[height][width] == 'E')
		game->exit_count++;
	if (game->map[height][width] == 'P')
		game->player_count++;
}

void	check_character(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			check_map(game, height, width);
			width++;
		}
		height++;
	}
	if (game->player_count != 1 || game->collectables < 1
		|| game->exit_count != 1)
	{
		ft_printf("Error\nIssue with player, exit or collectibles \n");
		exit_game(game);
	}
}

void	check_errors(t_game *game)
{
	int	vertical;
	int	horizontal;

	vertical = is_vertical_wall(game);
	horizontal = is_horizontal_wall(game);
	if (!vertical || !horizontal)
	{
		ft_printf("Error\nmissing walls\n");
		exit_game(game);
	}
	check_character(game);
	game->collectables_check = 0;
	game->exit_count_check = 0;
	game->valid_path = 0;
	allocate_map_check(game);
	check_path(game, game->x_axis, game->y_axis);
	if (game->exit_count_check < 1
		|| game->collectables_check < game->collectables)
	{
		ft_printf("Error\nMap must have a valid path\n");
		exit_game(game);
	}
	free_map_check(game);
}
