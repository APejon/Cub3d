/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:11:47 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/29 00:36:41 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_map
{
	char			**map;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				floor[3];
	int				ceiling[3];
	int				px;
	int				py;
	int				wide;
	int				high;
	char			player_dir;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
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
int		error_free(t_game *game, t_map *map, char *str);
int		side_check(t_map *map);
void	free_double_array(char **array);
int		prep_img(t_map *map);
int		spclen(char *str, int i);
int		player_count(t_map *map);

#endif