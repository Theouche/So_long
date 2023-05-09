/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:39:03 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/09 15:53:08 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **mapbis)
{
	int	i;
	//int	j;

	i = 0;
	write(1, "ok1\n", 4);
	if (!mapbis)
		return ;
	while (mapbis[i])
	{
		//write(1, "ok2\n", 4);
		free(mapbis[i]);
		i++;
	}
	//write(1, "ok3\n", 4);
	free(mapbis);
}
