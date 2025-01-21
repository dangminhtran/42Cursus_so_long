/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:18:10 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/17 19:43:42 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	right_move(t_game *game, int i, int j)
{
	if ((i < 0 && j < 0 && i >= game->width && j >= game->height)
		|| game->map[j][i] == '1')
		return (0);
	if (game->map[j][i] == 'E')
	{
		if (game->collectables == 0)
		{
			ft_printf("You escaped ! Yeah!\n");
			exit_game(game);
		}
		ft_printf("You can't leave ! Collect all the coins !\n");
	}
	if (game->map[j][i] == 'C')
		game->collectables--;
	if (game->map[j][i] != 'E')
		game->map[j][i] = 'P';
	game->counter++;
	game->x_axis = i;
	game->y_axis = j;
	return (1);
}

static int	keyboard_up_down(t_game *game, int movement)
{
	int	k;

	if (game->map[game->y_axis][game->x_axis] == '1')
		return (0);
	k = right_move(game, game->x_axis, game->y_axis + movement);
	if (!k)
		return (0);
	if (game->map[game->y_axis - movement][game->x_axis] == 'E'
		&& game->collectables != 0)
		game->map[game->y_axis - movement][game->x_axis] = 'E';
	else
		game->map[game->y_axis - movement][game->x_axis] = '0';
	ft_printf("Steps Done: %i\n", game->counter);
	return (1);
}

static int	keyboard_left_right(t_game *game, int movement)
{
	int	k;

	if (game->map[game->y_axis][game->x_axis] == '1')
		return (0);
	k = right_move(game, game->x_axis + movement, game->y_axis);
	if (!k)
		return (0);
	if (game->map[game->y_axis][game->x_axis - movement] == 'E'
		&& game->collectables != 0)
		game->map[game->y_axis][game->x_axis - movement] = 'E';
	else
		game->map[game->y_axis][game->x_axis - movement] = '0';
	ft_printf("Steps Done: %i\n", game->counter);
	return (1);
}

int	controls_working(int command, t_game *game)
{
	int	works;

	if (command == 119)
		works = keyboard_up_down(game, -1);
	if (command == 115)
		works = keyboard_up_down(game, 1);
	if (command == 97)
		works = keyboard_left_right(game, -1);
	if (command == 100)
		works = keyboard_left_right(game, 1);
	if (command == 65307)
		exit_game(game);
	if (works)
		adding_in_graphics(game);
	return (1);
}
