/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:44:05 by dangtran          #+#    #+#             */
/*   Updated: 2025/01/21 17:03:09 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/includes/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	int		fd;
	int		height;
	int		width;
	int		player_count;
	int		player_count_check;
	int		exit_count_check;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	int		collectables_check;
	int		valid_path;

	char	**map;
	char	**map_check;

	void	*grass;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}			t_game;

int			exit_game(t_game *game);
int			read_map(t_game *game, char **argv);
void		display_graphics(t_game *game);
void		load_player(t_game *game, int height, int width);
void		load_collectable(t_game *game, int height, int width);
void		display_images_in_game(t_game *game);
void		check_character(t_game *game);
void		check_map(t_game *game, int height, int width);
void		check_path(t_game *game, int x, int y);
void		check_errors(t_game *game);
int			controls_working(int command, t_game *game);
void		free_map_check(t_game *game);
void		allocate_map_check(t_game *game);
void		find_player_position(t_game *game);
void		destroy_game(t_game *game);
void		free_map(t_game *game);
void		*ft_memset(void *b, int c, size_t length);

#endif