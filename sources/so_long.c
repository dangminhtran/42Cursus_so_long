/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:00:48 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/18 17:29:54 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

void	destroy_game(t_game *game)
{
	if (game->grass)
		mlx_destroy_image(game->mlxpointer, game->grass);
	if (game->wall)
		mlx_destroy_image(game->mlxpointer, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlxpointer, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlxpointer, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlxpointer, game->collectable);
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	if (game->mlxpointer)
		mlx_destroy_display(game->mlxpointer);
	free(game->mlxpointer);
}

void	free_map_check(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_check)
	{
		while (i < game->height)
		{
			free(game->map_check[i]);
			i++;
		}
		free(game->map_check);
		game->map_check = NULL;
	}
}

int	exit_game(t_game *game)
{
	int	line;

	line = 0;
	destroy_game(game);
	while (line < game->height)
		free(game->map[line++]);
	free(game->map);
	free_map_check(game);
	exit(0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(1);
}
