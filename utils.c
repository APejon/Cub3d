/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:04:00 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/25 22:44:14 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	error_free(t_game *game, t_map *map, char *str)
{
	printf("%s", str);
	free(game);
	free(map);
	exit(1);
}

int	spclen(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}
