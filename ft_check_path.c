/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:22:54 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/03 11:53:32 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_path_error(t_data *data, char **mapbis, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->l)
		{
			if (mapbis[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_next(t_data *data, char **mapbis, int x, int y)
{
	if (mapbis[x][y] == '1' || mapbis[x][y] == 'X')
		return ;
	mapbis[x][y] = 'X';
	if (x > 0)
		check_next(data, mapbis, x - 1, y);
	if (x < data->h - 1)
		check_next(data, mapbis, x + 1, y);
	if (y > 0)
		check_next(data, mapbis, x, y - 1);
	if (y < data->l - 1)
		check_next(data, mapbis, x, y + 1);
	return ;
}

static void	ft_find_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->l)
		{
			if (data->map[i][j] == 'P')
			{
				data->coord_x = i;
				data->coord_y = j;
			}
			j++;
		}
		i++;
	}
	return ;
}

char	**ft_stdup(t_data *data, char **map)
{
	char	**mapbis;
	int		i;
	size_t		j;

	mapbis = malloc(sizeof(char *) * data->h);
	i = 0;
	while (i < data->h)
	{
		mapbis[i] = malloc(sizeof(char) * ft_strlen(map[i]) + 1);
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			mapbis[i][j] = map[i][j];
			j++;
		}
		mapbis[i][j] = 0;
		i++;
	}
	return (mapbis);
}

int	check_path(t_data *data)
{
	char	**mapbis;

	mapbis = ft_stdup(data, data->map);
	ft_find_pos(data);
	check_next(data, mapbis, data->coord_x, data->coord_y);
	if (check_path_error(data, mapbis, 'C') || check_path_error(data, mapbis, 'E'))
	{
		if (check_path_error(data, mapbis, 'C'))
			ft_printf("ERROR\nAt least one collectible is unreacheable\n");
		if (check_path_error(data, mapbis, 'E'))
			ft_printf("ERROR\nThe exit is unreacheable\n");
		return (0);
	}
	return (1);
}
