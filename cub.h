/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:47 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/25 16:06:00 by gchernys         ###   ########.fr       */
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
	char	player_dir;
	char	floor[3];
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	ceiling[3];
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
int		check_top(t_map *map);
int		call_check(char *str, t_map *map, t_game *game);
int		check_flood(t_map *map, int x, int y);
int		check_symbol(t_map *map);
// void	find_rgb(t_map *mam);
int		inner_space(t_map *map);
void	error_free(t_game *game, t_map *map);
int		side_check(t_map *map);
void	free_double_array(char **array);
int		prep_img(t_map *map);

#endif