/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:44 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/20 15:57:52 by gchernys         ###   ########.fr       */
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
	// find_rgb(map);
	// game->mlx = mlx_init();
	// print_map(map);
}