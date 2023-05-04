/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:02:47 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/04 10:02:58 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_map(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		printf("%s\n", map[j]);
		j++;
	}
}
