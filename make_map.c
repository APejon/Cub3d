/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:16:27 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/04 10:04:30 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	set_dimensions(t_map *map, char *file)
{
	int		height;
	char	*temp;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
		return (MALLOC_ERR);
	height = 0;
	map->wide = 0;
	i = 0;
	while (temp != NULL)
	{
		i = ft_strlen(temp);
		if (map->wide < i)
			map->wide = i;
		if (ft_strcmp(temp, "\n") != 0)
			height++;
		temp = get_next_line(fd);
	}
	free(temp);
	map->high = height;
	close(fd);
	return (0);
}

static void	setmap(char **tempmap, t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (tempmap[j] != NULL)
	{
		i = 0;
		ft_strlcpy(map->map[j], tempmap[j], map->wide + 1);
		while (i < map->wide && j > 5)
		{
			if (!ft_strchr("NSEW10", map->map[j][i]) || map->map[j][i] == '\0')
				map->map[j][i] = 'x';
			i++;
			if (i == map->wide)
				map->map[j][i] = '\0';
		}
		j++;
	}
	map->map[j] = NULL;
}

int	malloc_map(t_map *map, char *file)
{
	int	i;

	if (set_dimensions(map, file))
		return (MALLOC_ERR);
	i = 0;
	map->map = malloc(sizeof(char *) * (map->high + 1));
	if (map->map == NULL)
		return (MALLOC_ERR);
	while (i < map->high)
	{
		map->map[i] = malloc(sizeof(char) * (map->wide + 1));
		if (map->map[i] == NULL)
			return (MALLOC_ERR);
		i++;
	}
	map->player = malloc(sizeof(t_player));
	return (0);
}

int	load_map(t_game *game, t_map *map, char *file)
{
	int		fd;
	char	*temp;
	char	*str;
	char	**map_temp;

	str = NULL;
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		str = ft_strjoin_gnl(str, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	map_temp = ft_split(str, '\n');
	setmap(map_temp, map);
	free_double_array(map_temp);
	free(str);
	validate_map(map, game);
	return (0);
}

int	validate_map(t_map *map, t_game *game)
{
	if (validate_vertices(map->map, map))
		return_error("\nError: Invalid vertices in map\n\n", map, game);
	if (validate_sides(map->map))
		return_error("\nError: Invalid sides in map\n\n", map, game);
	if (validate_space(map->map))
		return_error("\nError: Invalid space in map\n\n", map, game);
	if (validate_player_count(map->map))
		return_error("\nError: Invalid amount of players in map\n\n", map, game);
	if (set_textures(map))
		return_error("\nError: Invalid textures\n\n", map, game);
	return (0);
}
