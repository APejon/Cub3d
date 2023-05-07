/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:29:17 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/07 06:36:17 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_double_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	return_error(char *str, t_map *map, t_game *game)
{
	if (map->map)
		free_double_array(map->map);
	free(map->player);
	free(map);
	free(game);
	ft_putstr_fd(str, 2);
	exit(1);
}
