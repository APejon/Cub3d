/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:22:17 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/28 23:56:39 by gchernys         ###   ########.fr       */
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

int	check_top(t_map *map)
{
	int		i;
	char	**tempmap;

	i = 0;
	tempmap = map->map;
	tempmap[6] = map->map[6];
	while (ft_isspace(tempmap[6][i]))
		i++;
	if (tempmap[6][0] == '0')
		i++;
	while (tempmap[6][i])
	{
		if (tempmap[6][i] == ' ')
			i++;
		if (tempmap[6][i] != '1')
		{
			if (tempmap[6][ft_strlen(tempmap[6]) - 1] == '0')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	inner_space(t_map *map)
{
	int	i;
	int	j;

	j = 7;
	while (map->map[j])
	{
		i = 0;
		while ((map->map[j][i]) != '\0')
		{
			if (map->map[j][i] == '0')
			{
				if (map->map[j + 1] == NULL || map->map[j - 1] == NULL)
					return (1);
				if (map->map[j][i + 1] == ' ' || map->map[j][i + 1] == '\0' || \
				map->map[j][i - 1] == ' ' || map->map[j][i - 1] == '\0')
					return (1);
				if (map->map[j + 1][i] == ' ' || map->map[j + 1][i] == '\0' || \
				map->map[j - 1][i] == ' ' || map->map[j - 1][i] == '\0')
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

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
				map->player_dir = c;
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	side_check(t_map *map)
{
	int	right;
	int	left;
	int	j;

	j = 6;
	while (map->map[j])
	{
		left = 0;
		right = ft_strlen(map->map[j]) - 1;
		while (map->map[j][left] == ' ' || map->map[j][left] == '\t')
			left++;
		if ((map->map[j][left] != '1' || map->map[j][right] != '1') && \
		(map->map[j][left] != 'E' || map->map[j][right] != 'E'))
			return (1);
		j++;
	}
	return (0);
}
