/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:19:20 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/30 17:16:47 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	setmap(char *file, t_map *map, t_game *game)
{
	int		fd;
	char	*temp;
	char	*str;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	str = NULL;
	temp = get_next_line(fd);
	if (!temp)
		error_free(game, map, "Error: Empty file\n");
	while (temp != NULL)
	{
		if (ft_strncmp(temp, "\n", 1) != 0)
			count++;
		if (count > 6)
			if (ft_strncmp(temp, "\n", 1) == 0)
				error_free(game, map, "Error: Empty line in map\n");
		str = ft_strjoin_gnl(str, temp);
		temp = get_next_line(fd);
	}
	free(temp);
	fd = call_check(str, map, game);
	close (fd);
	return (fd);
}

int	prep_img(t_map *map)
{
	int	j;

	j = 0;
	while (j < 6)
	{
		map->map[j] = ft_strtrim(map->map[j], " \t");
		if (ft_strncmp(map->map[j], "NO", 2) == 0)
			map->north = ft_substr(map->map[j], \
			spclen(map->map[j], 3), ft_strlen(map->map[j]));
		if (ft_strncmp(map->map[j], "SO", 2) == 0)
			map->south = ft_substr(map->map[j], \
			spclen(map->map[j], 3), ft_strlen(map->map[j]));
		if (ft_strncmp(map->map[j], "WE", 2) == 0)
			map->west = ft_substr(map->map[j], \
			spclen(map->map[j], 3), ft_strlen(map->map[j]));
		if (ft_strncmp(map->map[j], "EA", 2) == 0)
			map->east = ft_substr(map->map[j], \
			spclen(map->map[j], 3), ft_strlen(map->map[j]));
		j++;
	}
	if (ft_strlen(map->north) == 0 || ft_strlen(map->east) == 0 || \
		ft_strlen(map->south) == 0 || ft_strlen(map->west) == 0)
		return (1);
	else
		return (0);
}

void	check_map_by_lines(const char *str, t_map *map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	map->map = ft_split(str, '\n');
	while (map->map[height] != NULL)
	{
		width = ft_strlen(map->map[height]);
		map->wide = width;
		if (map->wide < width)
			map->wide = width;
		height++;
		width = 0;
	}
	map->high = height - 1;
	print_map(map);
}

int	call_check(char *str, t_map *map, t_game *game)
{
	int	error;

	error = 0;
	if (str == NULL)
		return (0);
	check_map_by_lines(str, map);
	error = check_symbol(map);
	if (error)
		error_free(game, map, "error: Invalid Symbol in map\n");
	error = check_top(map);
	if (error)
		error_free(game, map, "error: Invalid top of map\n");
	error = side_check(map);
	if (error)
		error_free(game, map, "error: Invalid side of map\n");
	error = inner_space(map);
	if (error)
		error_free(game, map, "error: found a \"0\" touching an empty space\n");
	error = player_count(map);
	if (error)
		error_free(game, map, "error: Invalid amount of players\n");
	return (error);
}

int	player_count(t_map *map)
{
	int i;
	int j;
	int count;

	count = 0;
	j = 6;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			if (map->map[j][i] == 'N' || map->map[j][i] == 'W' || \
				map->map[j][i] == 'E' || map->map[j][i] == 'S')
				count++;
			i++;
		}
		j++;
	}
	if (count != 1)
		return (1);
	return (0);
}

void	print_map(t_map *map)
{
	int i = 0;

	while (map->map[i] != NULL)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}