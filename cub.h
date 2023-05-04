/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:37 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/04 10:00:00 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"

typedef enum e_error
{
	MALLOC_ERR = 1,
	PARSE_ERR,
}	t_error;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}		t_player;

typedef struct s_map
{
	t_player		*player;
	char			**map;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				floor[3];
	int				ceiling[3];
	int				wide;
	int				high;
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

/***************************PARSING***************************/
int		basic_error_check(int argc, char **argv);
int		malloc_map(t_map *map, char *file);
int		load_map(t_game *game, t_map *map, char *file);
int		validate_map(t_map *map, t_game *game);
int		validate_vertices(char **tempmap, t_map *map);
int		validate_space(char **tempmap);
int		validate_sides(char **tempmap);
int		validate_player_count(char **tempmap);
int		set_textures(t_map *map);
/***************************FREEING***************************/
void	free_double_array(char **arr);
int		return_error(char *str, t_map *map, t_game *game);

/*DELETE THESE DEBUG FUNCTIONS WE'LL NEVER NEED THEM EVER*/
void	print_map(char **map);
#endif