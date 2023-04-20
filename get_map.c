/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:19:20 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/20 21:47:24 by gchernys         ###   ########.fr       */
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
	}
	while (temp != NULL)
	{
		str = ft_strjoin_gnl(str, temp);
		temp = get_next_line(fd_error);
	}
	free(temp);
	fd_error = call_check(str, map);
	return (fd_error);
}

void	check_map_by_lines(const char *str, t_map *map)
{
	int	height;
	
	height = 0;
	map->map = ft_split(str, '\n');
	while (map->map[height] != NULL)
		height++;
	map->high = height - 1;
}

// void	find_rgb(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	floor_num;
// 	int	ceiling_num;

// 	i = 0;
// 	j = 0;
// 	ceiling_num = 0;
// 	floor_num = 0;
// 	while (map->map[j])
// 	{
// 		while (map->map[j][i])
// 		{
// 			if (map->map[j][i] == 'F')
// 			{
// 				map->floor[floor_num] = *ft_substr(map->map[j], i + 2, 3);
// 				// map->floor[floor_num + 1] = *ft_substr(map->map[j], i + 5, 3);
// 				// map->floor[floor_num + 2] = *ft_substr(map->map[j], i + 8, 3);
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	printf("%c\n", map->floor[0]);
// 	// printf("%c\n", map->floor[1]);
// 	// printf("%c\n", map->floor[2]);
// }

int	call_check(char *str, t_map *map)
{
	int	error;

	error = 0;
	if (str == NULL)
		return (0);
	check_map_by_lines(str, map);
	// error += check_top_bot(map);
	error += check_symbol(map);
	error += floodfill_check(map->map, map->py, map->px);
	if (error)
		printf("Map Error");
	return (error);
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