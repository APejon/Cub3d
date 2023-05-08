/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:37 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/08 18:25:19 by gchernys         ###   ########.fr       */
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
	char			*floor;
	char			*cil;
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

int				main(int argc, char **argv);

/***************************PARSING***************************/
int				malloc_map(t_map *map, char *file);
int				basic_error_check(int argc, char **argv);
int				load_map(t_game *game, t_map *map, char *file);
int				validate_map(t_map *map, t_game *game);
int				validate_vertices(char **tempmap, t_map *map);
int				validate_space(char **tempmap);
int				validate_sides(char **tempmap);
int				validate_player_count(char **tempmap);
int				set_textures(t_map *map);
void			setmap(char **tempmap, t_map *map);
int				check_textures(t_map *map);
int				find_rgb(t_map *map);
int				init_rgb(t_map *map);
int				set_dimensions(t_map *map, char *file);
unsigned long	setrgb(int red, int green, int blue);
int				check_rgb(char **str);
/***************************FREEING***************************/
void			free_double_array(char **arr);
int				return_error(char *str, t_map *map, t_game *game);

/*DELETE THESE DEBUG FUNCTIONS WE'LL NEVER NEED THEM EVER*/
void			print_map(char **map);
#endif