/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:22:17 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/20 22:10:37 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	basic_error_check(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
	{
		write(2, "Error: Invalid number of arguments", 34);
		exit(0);
	}
	str = argv[1];
	i = ft_strlen(argv[1]);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || \
	str[i - 3] != 'c' || str[i - 4] != '.')
	{
		write(2, "Error: File needs to end with \".cub\" extension", 46);
		exit(0);
	}
	if (open(argv[1], O_RDONLY) < 0)
	{
		write(2, "Couldn't open file", 18);
		exit(0);
	}
	return (0);
}

int	check_top_bot(t_map *map)
{
	int i;

	i = 0;
	while (map->map[6][i])
	{
		if (map->map[6][i] != '1' && !ft_isspace(map->map[6][i]))
			return (1);
		i++;
	}
	i = 0;
	while (map->map[map->high][i])
	{
		if (map->map[map->high][i] != '1' && !ft_isspace(map->map[map->high][i]))
			return (1);
		i++;
	}
	return (0);
}

// int	floodfill_check(char **map, int j, int i)
// {
// 	if (map[j][i] == ' ')
// 		return (1);
// 	// map->map[j][i] = '2';
// 	// print_map(map);
// 	if (map[j - 1][i] == '1')
// 		floodfill_check(map, j + 1, i);
// 	if (map[j + 1][i] == '1')
// 		floodfill_check(map, j - 1, i);
// 	if (map[j][i + 1] == '1')
// 		floodfill_check(map, j, i - 1);
// 	if (map[j][i - 1] == '1')
// 		floodfill_check(map, j, i + 1);
// 	return (0);
// }

int	check_symbol(t_map *map)
{
	int		i;
	int		j;
	char	c;

	j = 6;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			c = map->map[j][i];
			if (c != '1' && c != '0' && c != 'N' && c != 'S' && \
			c != 'E' && c != 'W' && !ft_isspace(c))
				return (1);
			if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
			{
				map->px = i;
				map->py = j;
			}
			i++;
		}
		j++;
	}
	return (0);
}
