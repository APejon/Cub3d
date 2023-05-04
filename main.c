/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:32 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/04 09:59:25 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	basic_error_check(argc, argv);
	game = malloc(sizeof(t_game));
	map = malloc(sizeof(t_map));
	if (map == NULL || game == NULL || malloc_map(map, argv[1]))
		return_error("\nError: Malloc error\n\n", map, game);
	load_map(game, map, argv[1]);
	return (0);
}
