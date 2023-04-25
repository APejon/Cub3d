/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:44 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/25 16:09:18 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	basic_error_check(argc, argv);
	game = malloc(sizeof(t_game));
	map = malloc(sizeof(t_map));
	setmap(argv[1], map, game);
	if (prep_img(map) == 1)
		error_free(game, map);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_free(game, map);
	// game->mlx_window = mlx_new_window(game->mlx, 500, 500, "cub3D");
	// if (!game->mlx_window)
		// error_free(game, map);
	// mlx_loop(game->mlx);
	free(game);
	free(map);
	return (0);
}
