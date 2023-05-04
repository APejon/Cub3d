/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:18:41 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/04 10:06:18 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_char(char **arr, int size, char c)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	while (i < size)
	{
		ptr = ft_strchr(arr[i], c);
		if (ptr != NULL)
		{
			*ptr = '\0';
			ft_strncpy(arr[i], arr[i] + 1, ft_strlen(arr[i]));
		}
		i++;
	}
}
