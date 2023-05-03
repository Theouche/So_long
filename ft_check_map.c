/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:20:51 by tlorne            #+#    #+#             */
/*   Updated: 2023/04/26 14:54:05 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//checker la forme = rectangle.
//checker les murs (que des 1 a l'exterieur)
//checker les lignes
//checker les doublons (1 E, 1 P et au moins 1 C)
//checker le chemin.

#include "so_long.h"

static int	check_db(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->l)
		{
			if (data->map[i][j] == 'C')
				data->env.count_c++;
			if (data->map[i][j] == 'E')
				data->env.count_e++;
			if (data->map[i][j] == 'P')
				data->env.count_p++;
			j++;
		}
		i++;
	}
	if (data->env.count_c < 1 || data->env.count_e > 1 || data->env.count_p > 1)
	{
		ft_printf("ERROR\nWrong map (Too many E or P or not enough C)\n");
		return (0);
	}
	return (1);
}

static int	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->l)
	{
		if (data->map[0][i] != '1' || data->map[data->h - 1][i] != '1')
		{
			ft_printf("ERROR\nProbleme with the upper or down wall\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < data->h)
	{
		if (data->map[i][0] != '1' || data->map[i][data->l - 1] != '1')
		{
			ft_printf("ERROR\nProbleme with the rigth or left wall\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->l)
		{
			ft_printf("ERROR\nSome line has different lenght\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_shape(t_data *data)
{
	int	i;
	int	j;

	data->h = 0;
	i = 0;
	while (data->map[i++])
		data->h++;
	j = 0;
	data->l = 0;
	while (data->map[0][j++])
		data->l++;
	if (data->l == data->h)
	{
		ft_printf("ERROR\nmap is not rectangular\n");
		return (0);
	}
	return (1);
}

int	check_map(t_data *data)
{
	data->env.exit = 'E';
	data->env.collect = 'C';
	data->env.player = 'P';
	data->env.wall = '1';
	data->env.empty = '0';
	data->env.count_c = 0;
	data->env.count_p = 0;
	data->env.count_e = 0;
	if (!check_shape(data) || !check_line(data) || !check_wall(data)
		|| !check_db(data) || !check_path(data))
		return (0);
	return (1);
}
