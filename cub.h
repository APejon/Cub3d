/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:47 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/20 21:47:17 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_map
{
	char	**map;
	int		px;
	int		py;
	int		wide;
	int		high;
	char	floor[3];
	char	ceilin[3];
}		t_map;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*mlx_window;
	void	*image;
}		t_game;

int		main(int argc, char **argv);
int		basic_error_check(int argc, char **argv);
char	setmap(char *file, t_map *map, t_game *game);
void	check_map_by_lines(const char *str, t_map *map);
void	print_map(t_map *map);
int		check_top_bot(t_map *map);
int		call_check(char *str, t_map *map);
int		surrounded_check(t_map *map);
int		check_symbol(t_map *map);
// void	find_rgb(t_map *mam);
int	floodfill_check(char **map, int j, int i);

#endif