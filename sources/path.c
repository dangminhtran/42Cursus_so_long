/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:04:57 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/21 14:24:20 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	allocate_map_check(t_game *game)
{
	int	i;

	i = 0;
	game->map_check = malloc(sizeof(char *) * game->height);
	if (!game->map_check)
	{
		ft_printf("Error\nMemory allocation failed for map_check\n");
		exit_game(game);
	}
	while (i < game->height)
	{
		game->map_check[i] = strdup(game->map[i]);
		if (!game->map_check[i])
		{
			ft_printf("Error\nMemory allocation failed for map_check row\n");
			exit_game(game);
		}
		i++;
	}
}

void	check_path(t_game *game, int x, int y)
{
	if (game->exit_count_check == 1
		&& game->collectables == game->collectables_check)
	{
		game->valid_path = 1;
		return ;
	}
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (game->map_check[y][x] == '1' || game->map_check[y][x] == 'X')
		return ;
	if (game->map_check[y][x] == 'C')
		game->collectables_check++;
	else if (game->map_check[y][x] == 'E')
		game->exit_count_check++;
	game->map_check[y][x] = 'X';
	check_path(game, x, y - 1);
	check_path(game, x, y + 1);
	check_path(game, x - 1, y);
	check_path(game, x + 1, y);
}
