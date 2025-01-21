/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:22:16 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 17:33:09 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	if (!game.mlxpointer)
		free_map(&game);
	game.winpointer = mlx_new_window(game.mlxpointer, (game.width * 40),
			(game.height * 40), "solong");
	if (!game.winpointer)
	{
		mlx_destroy_display(game.mlxpointer);
		free(game.mlxpointer);
		return (1);
	}
	display_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
	return (0);
}
