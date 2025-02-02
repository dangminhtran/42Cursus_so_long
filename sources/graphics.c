/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:00:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/21 17:35:44 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, game->winpointer,
		game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	load_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, game->winpointer,
		game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	put_image(t_game *game, char tile, int width, int height)
{
	void	*image;

	if (tile == '1')
		image = game->wall;
	else if (tile == 'E')
		image = game->exit;
	else if (tile == '0')
		image = game->grass;
	else
		return ;
	mlx_put_image_to_window(game->mlxpointer, game->winpointer,
		image, width * 40, height * 40);
}

void	display_images_in_game(t_game *game)
{
	int	i;
	int	j;

	game->grass = mlx_xpm_file_to_image(game->mlxpointer,
			"images/grass.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"images/collectible.xpm", &i, &j);
	if (game->grass == NULL || game->wall == NULL || game->player == NULL
		|| game->exit == NULL || game->collectable == NULL)
	{
		ft_printf("Error\nFailed to load images\n");
		exit_game(game);
	}
}

void	display_graphics(t_game *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'C')
				load_collectable(game, height, width);
			else if (game->map[height][width] == 'P')
				load_player(game, height, width);
			else
				put_image(game, game->map[height][width], width, height);
			width++;
		}
		height++;
	}
}
