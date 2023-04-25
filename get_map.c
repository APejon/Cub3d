/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:19:20 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/25 16:11:08 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	setmap(char *file, t_map *map, t_game *game)
{
	int		fd_error;
	char	*temp;
	char	*str;

	fd_error = open(file, O_RDONLY);
	str = NULL;
	temp = get_next_line(fd_error);
	if (!temp)
	{
		ft_printf("%s", "empty file");
		free(game);
		free(map);
		exit(1);
	}
	while (temp != NULL)
	{
		str = ft_strjoin_gnl(str, temp);
		temp = get_next_line(fd_error);
	}
	free(temp);
	fd_error = call_check(str, map, game);
	return (fd_error);
}

int	prep_img(t_map *map)
{
	int	j;

	j = 0;
	while (j < 6)
	{
		if (ft_strncmp(map->map[j], "NO", 2) == 0)
			map->north = ft_substr(map->map[j], 3, ft_strlen(map->map[j]));
		if (ft_strncmp(map->map[j], "SO", 2) == 0)
			map->south = ft_substr(map->map[j], 3, ft_strlen(map->map[j]));
		if (ft_strncmp(map->map[j], "WE", 2) == 0)
			map->west = ft_substr(map->map[j], 3, ft_strlen(map->map[j]));
		if (ft_strncmp(map->map[j], "EA", 2) == 0)
			map->east = ft_substr(map->map[j], 3, ft_strlen(map->map[j]));
		j++;
	}
	if (map->north == NULL || map->south == NULL || map->west == NULL
		|| map->east == NULL)
		return (1);
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
}

int	call_check(char *str, t_map *map, t_game *game)
{
	int	error;

	error = 0;
	if (str == NULL)
		return (0);
	check_map_by_lines(str, map);
	error += check_symbol(map);
	error += check_top(map);
	error += side_check(map);
	if (error)
		error_free(game, map);
	error += inner_space(map);
	if (error)
		error_free(game, map);
	return (error);
}

// void	print_map(t_map *map)
// {
// 	int i = 0;

// 	while (map->map[i] != NULL)
// 	{
// 		printf("%s\n", map->map[i]);
// 		i++;
// 	}
// }